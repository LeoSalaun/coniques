#pragma once


#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>
#include <limits>

#include <Eigen/Dense>

#include "Shape.hpp"

namespace ConicClass{

	class Conic : public Shape {

	public :
		Conic(const std::vector<Eigen::VectorXd> points);
		Conic();
		~Conic();
		
		Eigen::MatrixXd getMatrixFromPoints() const;
		Eigen::VectorXd getConicFromPoints() const;
		Eigen::VectorXd getLineCoeffFromPoints(const Eigen::VectorXd &pt1, const Eigen::VectorXd &pt2);
		Eigen::VectorXd getIntersectionFromLines(const Eigen::VectorXd &l1, const Eigen::VectorXd &l2);
		void addPointsToConic(std::vector<Eigen::VectorXd> listePoints, int nbPoints, Viewer_conic &viewer);
		void display(Viewer_conic &viewer) const override;

	};
}