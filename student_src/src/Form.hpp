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

class Form {

private :
	std::vector<Eigen::VectoXd> m_points;


public :
	void display() const;

}
