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

class Line : public Forme {

public :
	void display() const override{
        viewer.push_line(pt1, pt2-pt1, 200,200,0);
    };

}