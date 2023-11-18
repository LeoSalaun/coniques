#include <iostream>
#include <vector>
#include <chrono>
#include <random>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"



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
	std::uniform_real_distribution<float> distrib(-200,200);

  int nombreDePoints = 1000000;

  std::vector<Eigen::VectorXd> listePoints;

  for (int i = 0; i < nombreDePoints; ++i) {
    Eigen::VectorXd point(2);
    point << distrib(generator), distrib(generator);
    listePoints.push_back(point);
  }

  // draw points
  /*Eigen::VectorXd pt1(2), pt2(2), pt3(2), pt4(2), pt5(2);
  pt1 <<  distrib(generator), distrib(generator);
  pt2 <<  distrib(generator),  distrib(generator);
  pt3 << distrib(generator), distrib(generator);
  pt4 << distrib(generator), distrib(generator);
  pt5 << distrib(generator), distrib(generator);*/

  for (int i = 0; i < nombreDePoints; ++i) {
    std::string nom = "pt" + std::to_string(i +1);
    viewer.push_point(listePoints[i].transpose(), nom, 200,0,0);
  }

  /*viewer.push_point(pt1, "p1", 200,0,0);
  viewer.push_point(pt2, "p2", 200,0,0);
  viewer.push_point(pt3, "p3", 200,0,0);
  viewer.push_point(pt4, "p4", 200,0,0);
  viewer.push_point(pt5, "p5", 200,0,0);*/
  // draw line
  /*viewer.push_line(pt1, pt2-pt1,  200,200,0);
  viewer.push_line(pt1, pt4-pt1,  200,200,0);
  viewer.push_line(pt2, pt5-pt2,  200,200,0);
  viewer.push_line(pt5, pt3-pt5,  200,200,0);
  viewer.push_line(pt3, pt4-pt3,  200,200,0);*/

  // draw conic
  Eigen::VectorXd conic(6);
  //conic << -1.4, -0.3, -1, -0.6, 0.0, 0.8;
  conic << -1.4, -0.3, -1, -0.6, 0.0, 2.8;
  viewer.push_conic(conic, 0,0,200);

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  return 0;
}

