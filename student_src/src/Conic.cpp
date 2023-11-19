#include <iostream>

#include "Conic.hpp"
#include "Geogebra_conics.hpp"

Eigen::MatrixXd Conic::getMatrixFromPoints() {
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

Eigen::VectorXd Conic::getConicFromPoints() {
	Eigen::MatrixXd A = getMatrixFromPoints(points);
	std::cout << A << std::endl;
	Eigen::JacobiSVD<Eigen::MatrixXd> svd (A, Eigen::ComputeThinU | Eigen::ComputeFullV);
	return svd.matrixV().rightCols (1);
}

void Conic::display(Viewer_conic viewer) {
	viewer.push_conic(getConicFromPoints(), 0,0,200);
}
