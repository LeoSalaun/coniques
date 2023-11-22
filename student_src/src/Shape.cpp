#include <iostream>

#include "Shape.hpp"

Shape::Shape(const std::vector<Eigen::VectorXd> points)
	: m_points(points)
{}

Shape::Shape()
	: m_points()
{}

//Shape::~Shape(){
//	m_points.clear();
//}

//std::vector<Eigen::VectorXd> Shape::getPoints() const {
//	return m_points;
//}
