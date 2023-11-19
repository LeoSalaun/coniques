#pragma once


#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>
#include <limits>

#include <Eigen/Dense>

#include "Entry.hpp"
#include "Directory.hpp"
#include "Geogebra_conics.hpp"

class Form {

protected :
	std::vector<Eigen::VectorXd> m_points;


public :
	Form(const std::vector<Eigen::VectorXd> points);
	Form();
	~Form();
	
	virtual void display(Viewer_conic viewer) const;
	
	std::vector<Eigen::VectorXd> getPoints();
	inline void setPoints(std::vector<Eigen::VectorXd> points) {m_points = points;}
	inline void addPoint(Eigen::VectorXd pt) {m_points.push_back(pt);};
};
