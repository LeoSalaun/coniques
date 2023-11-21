#include <iostream>

#include "Conic.hpp"
#include "Geogebra_conics.hpp"

Conic::Conic(const std::vector<Eigen::VectorXd> points)
	: Form(points) {}

Conic::Conic()
	: Form() {}

Conic::~Conic() {
	m_points.clear();
}

Eigen::MatrixXd Conic::getMatrixFromPoints() const {
	size_t nbPoints = m_points.size();
	Eigen::MatrixXd A(nbPoints,6);
	for (size_t i=0 ; i<nbPoints ; i++) {
		A(i,0) = std::pow(m_points[i](0),2);
		A(i,1) = m_points[i](0)*m_points[i](1);
		A(i,2) = std::pow(m_points[i](1),2);
		A(i,3) = m_points[i](0);
		A(i,4) = m_points[i](1);
		A(i,5) = 1; // Coordonnée homogène
	}
	return A;
}

Eigen::VectorXd Conic::getConicFromPoints() const {
	Eigen::MatrixXd A = this->getMatrixFromPoints();
	std::cout << A << std::endl;
	Eigen::JacobiSVD<Eigen::MatrixXd> svd (A, Eigen::ComputeThinU | Eigen::ComputeFullV);
	return svd.matrixV().rightCols (1);
}

void Conic::display(Viewer_conic viewer) const {
	viewer.push_conic(getConicFromPoints(), 0,0,200);
}
