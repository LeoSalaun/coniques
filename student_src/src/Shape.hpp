#pragma once


#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>
#include <limits>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"

class Shape {

protected :
	std::vector<Eigen::VectorXd> m_points;


public :
	Shape(const std::vector<Eigen::VectorXd> points);
	Shape();
	~Shape() {};
	
	virtual void display(Viewer_conic &viewer) const = 0;
	
	inline std::vector<Eigen::VectorXd> getPoints() const {return m_points;};
	inline Eigen::VectorXd getPoint(const size_t index) const {return m_points[index];};
	inline void setPoints(std::vector<Eigen::VectorXd> points) {m_points = points;}
	inline void addPoint(Eigen::VectorXd pt) {m_points.push_back(pt);};
};
