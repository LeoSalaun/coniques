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
#include "Shape.hpp"

class Line : public Shape {

public :
    Line(const std::vector<Eigen::VectorXd> points);
	Line();
	~Line();
	
	Eigen::VectorXd getLineCoeffFromPoints(const Eigen::VectorXd &pt1, const Eigen::VectorXd &pt2);
	void display(Viewer_conic &viewer) const override;

};