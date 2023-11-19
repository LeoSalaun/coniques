#include <iostream>

#include "Form.hpp"

Form::Form(const std::vector<Eigen::VectorXd> points)
	: m_points(points)
{}

Form::Form(){
	m_points = {};
}

Form::~Form(){
	delete[] m_points;
}

std::vector<Eigen::VectorXd> Form::getPoints() {
	return m_points;
}
