#include <iostream>

#include "Form.hpp"

Form::Form(const std::vector<Eigen::VectorXd> points)
	: m_points(points)
{}

Form::Form()
	: m_points(0)
{}

//Form::~Form(){
//	m_points.clear();
//}

//std::vector<Eigen::VectorXd> Form::getPoints() const {
//	return m_points;
//}
