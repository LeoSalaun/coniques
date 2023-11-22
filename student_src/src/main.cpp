#include <iostream>
#include <vector>
#include <chrono>
#include <random>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"

////////////////////////////////////////////
// Temporary

Eigen::MatrixXd getMatrixFromPoints(const std::vector<Eigen::VectorXd> &points) {
	Eigen::MatrixXd A(points.size(),6);
	for (size_t i=0 ; i<points.size() ; i++) {
		A(i,0) = std::pow(points[i](0),2);
		A(i,1) = points[i](0)*points[i](1);
		A(i,2) = std::pow(points[i](1),2);
		A(i,3) = points[i](0);
		A(i,4) = points[i](1);
		A(i,5) = 1; // Coordonnée homogène
	}
	return A;
}

Eigen::VectorXd getConicFromPoints(const std::vector<Eigen::VectorXd> &points) {
	Eigen::MatrixXd A = getMatrixFromPoints(points);
	std::cout << A << std::endl;
	Eigen::JacobiSVD<Eigen::MatrixXd> svd (A, Eigen::ComputeThinU | Eigen::ComputeFullV);
	return svd.matrixV().rightCols (1);
}

////////////////////////////////////////////

int main()
{
  // the viewer will open a file whose path is writen in hard (bad!!). 
  // So you should either launch your program from the fine directory or change the path to this file.
  Viewer_conic viewer;

  // viewer options
  viewer.set_background_color(250, 250, 255);
  viewer.show_axis(true);
  viewer.show_grid(false);
  viewer.show_value(false);
  viewer.show_label(true);

  //aleatoire points
  // select a random generator engine and a distribution
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<float> distrib(-4,4);

  int nombreDePoints = 5;

  std::vector<Eigen::VectorXd> listePoints;

  for (int i = 0; i < nombreDePoints; ++i) {
    Eigen::VectorXd point(2);
    point << distrib(generator), distrib(generator);
    listePoints.push_back(point);
    std::string nom = "pt" + std::to_string(i +1);
    viewer.push_point(listePoints[i].transpose(), nom, 200,0,0);
  }

  //draw line
  //viewer.push_line(pt1, pt2-pt1, 200,200,0);

  // draw conic
  //Eigen::VectorXd conic(6);
  //conic << -1.4, -0.3, -1, -0.6, 0.0, 0.8;
  Eigen::VectorXd conic = getConicFromPoints(listePoints);
  viewer.push_conic(conic, 0,0,200);

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  return 0;
}
