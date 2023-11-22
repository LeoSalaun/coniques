#include <iostream>

#include "Conic.hpp"
#include "Geogebra_conics.hpp"

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

Eigen::VectorXd Conic::getConicFromPoints() const {
	Eigen::MatrixXd A = this->getMatrixFromPoints();
	std::cout << A << std::endl;
	Eigen::JacobiSVD<Eigen::MatrixXd> svd (A, Eigen::ComputeThinU | Eigen::ComputeFullV);
	return svd.matrixV().rightCols (1);
}

Eigen::VectorXd Conic::getLineCoeffFromPoints(const Eigen::VectorXd &pt1, const Eigen::VectorXd &pt2) {
	assert(pt1.size() == 2 && "Erreur dans la définition des coordonnées des points");
    	assert(pt2.size() == 2 && "Erreur dans la définition des coordonnées des points");

	Eigen::VectorXd coeff(2);
	double m = (pt1(1)-pt2(1))/(pt1(0)-pt2(0));
	double b = pt1(1)-m*pt1(0);
	coeff << m,b;
	return coeff;	
}

Eigen::VectorXd Conic::getIntersectionFromLines(const Eigen::VectorXd &l1, const Eigen::VectorXd &l2) {
	assert(l1.size() == 2 && "Erreur dans la définition des coefficients des droites");
    	assert(l2.size() == 2 && "Erreur dans la définition des coefficients des droites");
	
	Eigen::VectorXd ptIntersect(2);
	double x = (-l1(1)+l2(1))/(l1(0)-l2(0));
	double y = l1(0)*x+l1(1);
	ptIntersect << x,y;
	return ptIntersect;	
}

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

void Conic::display(Viewer_conic &viewer) const {
	viewer.push_conic(getConicFromPoints(), 0,0,200);
}

/////////////////// Tentative d'implémentation des faisceaux

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

Conic Conic::faisceau(Conic conique, double t) const {
	return (*this)*std::cos(t) + conique*std::sin(t);
}
