#pragma once


#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>
#include <limits>

#include <Eigen/Dense>

#include "Form.hpp"



class Conic : public Form {

public :
	Conic(const std::vector<Eigen::VectorXd> points);
	Conic();
	~Conic();
	
	Eigen::MatrixXd getMatrixFromPoints() const;
	Eigen::VectorXd getConicFromPoints() const;
	void display(Viewer_conic viewer) const override;

};
