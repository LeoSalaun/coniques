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
	
	/**
	Returns the list of the points of the conic.
	**/
	inline std::vector<Eigen::VectorXd> getPoints() const {return m_points;};
	
	/**
	Returns the point of the conic at the given index.
	index -> index
	**/
	inline Eigen::VectorXd getPoint(const size_t &index) const {return m_points[index];};
	
	/**
	Sets the points of the conic at the given list of points.
	points -> given list of points
	**/
	inline void setPoints(const std::vector<Eigen::VectorXd> &points) {m_points = points;}
	
	/**
	Adds a point to the conic.
	pt -> point to add
	**/
	inline void addPoint(const Eigen::VectorXd &pt){m_points.push_back(pt);};
	
	/**
	Adds a few points to the conic.
	pt -> point to add
	... args -> list of the other points to add
	**/
	template < typename ... Args >
	inline void addPoint(const Eigen::VectorXd &pt, const Args ... args){m_points.push_back(pt); this->addPoint(args ...);}
};
