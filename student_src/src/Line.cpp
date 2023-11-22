#include <iostream>

#include "Line.hpp"
#include "Geogebra_conics.hpp"

Line::Line(const std::vector<Eigen::VectorXd> points)
	: Shape(points) {}

Line::Line()
	: Shape() {}

Line::~Line() {
	m_points.clear();
}

Eigen::VectorXd getLineCoeffFromPoints(const Eigen::VectorXd &pt1, const Eigen::VectorXd &pt2) {
	Eigen::VectorXd coeff(2);
	double m = (pt1(1)-pt2(1))/(pt1(0)-pt2(0));
	double b = pt1(1)-m*pt1(0);
	coeff << m,b;
	return coeff;	
}

void Line::display(Viewer_Line &viewer) const {
	viewer.push_Line(m_points[0],m_points[1], 200,200,0);
}
