#include <iostream>

#include "Conic.hpp"
#include "Geogebra_conics.hpp"

namespace ConicClass{
	Conic::Conic(const std::vector<Eigen::VectorXd> points)
		: Shape(points) {
		for (const auto& point : points) {
			assert(point.size() == 2 && "Erreur dans la définition des coordonnées des points");
	    	}
	}

	Conic::Conic()
		: Shape() {}

	Conic::~Conic() {
		m_points.clear();
	}

	/**
	Builds a matrix from the points of the conic that represents the system to find the coefficients of the conic.
	**/
	Eigen::MatrixXd Conic::getMatrixFromPoints() const {
		for (const auto& point : m_points) {
			assert(point.size() == 2 && "Erreur dans la définition des coordonnées des points");
	    	}

		size_t nbPoints = m_points.size();
		Eigen::MatrixXd A(nbPoints,6);
		for (size_t i=0 ; i<nbPoints ; i++) {
			A(i,0) = std::pow(m_points[i](0),2);
			A(i,1) = m_points[i](0)*m_points[i](1);
			A(i,2) = std::pow(m_points[i](1),2);
			A(i,3) = m_points[i](0);
			A(i,4) = m_points[i](1);
			A(i,5) = 1; // Coordonnée homogène
		}
		return A;
	}
	
	/**
	Gets the coefficients from the points of the conic.
	**/
	Eigen::VectorXd Conic::getConicFromPoints() const {
		Eigen::MatrixXd A = this->getMatrixFromPoints();
		std::cout << A << std::endl;
		Eigen::JacobiSVD<Eigen::MatrixXd> svd (A, Eigen::ComputeThinU | Eigen::ComputeFullV);
		return svd.matrixV().rightCols (1);
	}
	
	/**
	Gets the equation of a line from two points.
	pt1 -> point of the line
	pt2 -> point of the line
	**/
	Eigen::VectorXd Conic::getLineCoeffFromPoints(const Eigen::VectorXd &pt1, const Eigen::VectorXd &pt2) {
		assert(pt1.size() == 2 && "Erreur dans la définition des coordonnées des points");
	    	assert(pt2.size() == 2 && "Erreur dans la définition des coordonnées des points");

			Eigen::VectorXd coeff(2);
			double m = (pt1(1)-pt2(1))/(pt1(0)-pt2(0));
			double b = pt1(1)-m*pt1(0);
			coeff << m,b;
			return coeff;	
		}
	
	/**
	Searchs the intersection point of two lines.
	l1 -> a line
	l2 -> a line
	**/
	Eigen::VectorXd Conic::getIntersectionFromLines(const Eigen::VectorXd &l1, const Eigen::VectorXd &l2) {
		assert(l1.size() == 2 && "Erreur dans la définition des coefficients des droites");
	    	assert(l2.size() == 2 && "Erreur dans la définition des coefficients des droites");
		
		Eigen::VectorXd ptIntersect(2);
		double x = (-l1(1)+l2(1))/(l1(0)-l2(0));
		double y = l1(0)*x+l1(1);
		ptIntersect << x,y;
		return ptIntersect;	
	}
	
	/**
	Searchs points to build a conic from tangents and adds these to the conic.
	listePoints -> list of the points that constitute the tangents
	nbPoints -> number of points constituting the tangents
	viewer -> Geogebra prompt
	**/
	void Conic::addPointsToConic(std::vector<Eigen::VectorXd> listePoints, int nbPoints, Viewer_conic &viewer){
		if (nbPoints < 5) {
			throw std::invalid_argument("Il n'y a pas suffisamment de points pour construire une conique.");
	    	}
		
		for (int i = 0; i < nbPoints; ++i) {
			Eigen::VectorXd currentLine(2), pointIntersect(2), diag1(2), diag2(2), diag3(2);
			viewer.push_line(listePoints[i], listePoints[(i+1)%nbPoints]-listePoints[i],  200,200,0);
			currentLine = getLineCoeffFromPoints(listePoints[i], listePoints[(i+1)%nbPoints]);
			//Find the two diagonals
			diag1 = getLineCoeffFromPoints(listePoints[i], listePoints[(i+2)%nbPoints]);
			diag2 = getLineCoeffFromPoints(listePoints[(i+1)%nbPoints], listePoints[(i+4)%nbPoints]);
			//Find intersection point
			pointIntersect = getIntersectionFromLines(diag1, diag2);
			//Find the last line and the intersection point and add the point
			diag3 = getLineCoeffFromPoints(listePoints[(i+3)%nbPoints], pointIntersect);
			this->addPoint(getIntersectionFromLines(currentLine, diag3));
		}
	}
	
	/**
	Displays the calculated conic on the Geogebra prompt.
	viewer -> Geogebra prompt
	**/
	void Conic::display(Viewer_conic &viewer) const {
		viewer.push_conic(getConicFromPoints(), 0,0,200);
	}

	/////////////////// Attempt to implement the conic beams ("faisceaux de coniques")
	/////////           Due to some lack of time, we could not finish and perform
	/////////           proper tests over the following methods ans operators.

	Conic &Conic::operator*(double alpha) const {
		Conic conique;
		for (size_t i=0 ; i<m_points.size() ; i++) {
			conique.addPoint(m_points[i]*alpha);
		}
		return conique;
	}

	Conic Conic::operator+(Conic conique) const {
		assert(m_points.size() == (conique.getPoints()).size() && "Vous ne pouvez additionner deux coniques ayant un nombre de points différents.");
		Conic res;
		for (size_t i=0 ; i<m_points.size() ; i++) {
			res.addPoint(m_points[i]+conique.getPoint(i));
		}
		return res;
	}
	
	/**
	Function that calculates a conic beam.
	conique -> second conic to take into account
	t -> a number between 0 and PI
	**/
	Conic Conic::faisceau(Conic conique, double t) const {
		return (*this)*std::cos(t) + conique*std::sin(t);
	}
}
