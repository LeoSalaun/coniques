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



class Conic : public Form {

public :
	Eigen::MatrixXd getMatrixFromPoints();
	Eigen::VectorXd getConicFromPoints();
	void display(Viewer_conic viewer);

};
