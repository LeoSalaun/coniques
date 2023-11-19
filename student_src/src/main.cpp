#include <iostream>
#include <vector>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"

////////////////////////////////////////////
// Temporary

Eigen::VectorXd gaussSeidel(const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const uint nbIter)
{
	// initial solution 
	Eigen::VectorXd x(b);

	// iterations
	for(uint iter=0; iter<nbIter; ++iter)
	for(int i=0; i<A.rows(); ++i){
		double sum = 0.0;
		for(int j=0; j<i; ++j)          sum += A(i,j)*x(j);
		for(int j=i+1; j<A.cols(); ++j)	sum += A(i,j)*x(j);
		x(i) = (b(i)-sum)/A(i,i);
	}

	return x;
}

Eigen::MatrixXd buildDiagonalStrictMatrix(const size_t n, double alpha){
	Eigen::MatrixXd A = Eigen::MatrixXd::Random(n,n);
	A.diagonal() = alpha * Eigen::VectorXd::Ones(n);
	return A;
}

unsigned int getRank(const Eigen::MatrixXd &A){
	Eigen::FullPivLU<Eigen::MatrixXd> lu_decomp(A);
	return lu_decomp.rank();
}

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

Eigen::VectorXd getConicFromPoints(const std::vector<Eigen::VectorXd> &points, const uint &nbIter) {
	Eigen::MatrixXd A = getMatrixFromPoints(points);
	std::cout << A << std::endl;
	Eigen::VectorXd b(6);
	b << 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001;
	std::cout << b << std::endl;
	return gaussSeidel(A, b, nbIter);
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

  // draw points
  Eigen::VectorXd pt1(2), pt2(2), pt3(2), pt4(2), pt5(2);
  pt1 <<  1.5,  2.0;
  pt2 <<  3.0,  1.0;
  pt3 << -2.0, -1.0;
  pt4 << -1.0, -2.0;
  pt5 <<  3.0, -1.0;

  viewer.push_point(pt1, "p1", 200,0,0);
  viewer.push_point(pt2, "p2", 200,0,0);
  viewer.push_point(pt3, "p3", 200,0,0);
  viewer.push_point(pt4, "p4", 200,0,0);
  viewer.push_point(pt5, "p5", 200,0,0);
  
  std::vector<Eigen::VectorXd> points = {pt1, pt2, pt3, pt4, pt5};

  // draw line
  viewer.push_line(pt1, pt2-pt1,  200,200,0);

  // draw conic
  //Eigen::VectorXd conic(6);
  //conic << -1.4, -0.3, -1, -0.6, 0.0, 0.8;
  uint nbIter = 1;
  Eigen::VectorXd conic = getConicFromPoints(points,nbIter);
  viewer.push_conic(conic, 0,0,200);

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  return 0;
}

