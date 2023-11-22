#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <stdexcept>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"
#include "Shape.hpp"
#include "Conic.hpp"

int main()
{
	// the viewer will open a file whose path is writen in hard (bad!!). 
	// So you should either launch your program from the fine directory or change the path to this file.
	Viewer_conic viewer;

	// viewer options
	viewer.set_background_color(250, 250, 255);
	viewer.show_axis(true);
	viewer.show_grid(false);
	viewer.show_value(false);
	viewer.show_label(true);

	//aleatoire points
	// select a random generator engine and a distribution
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<float> distrib(-4,4);

	long unsigned int nombreDePoints = 5;

	std::vector<Eigen::VectorXd> listePoints;
	
	int choix;
	std::cout << "Exemple : ";
	std::cin >> choix;
	
	/*	---- 	      EXAMPLE 1 	----	*/
	/*	---- Conic built from 5 points  ----	*/
	
	ConicClass::Conic conique;
	
	for (long unsigned int i = 0; i < nombreDePoints; ++i) {
		Eigen::VectorXd point(2);
		point << distrib(generator), distrib(generator);

    		assert(point.size() == 2 && "Erreur dans la définition des coordonnées des points");

		listePoints.push_back(point);
		conique.addPoint(point.transpose());
		std::string nom = "pt" + std::to_string(i +1);
		viewer.push_point(listePoints[i].transpose(), nom, 200,0,0);
	}

  	assert(conique.getPoints().size() == nombreDePoints && "Erreur dans l'enregistrement des points.");

  	if (nombreDePoints < 5) {
		throw std::invalid_argument("Il n'y a pas suffisamment de points pour construire une conique.");
	}
		
	if (choix == 1) conique.display(viewer);
	
	/*	---- 	       EXAMPLE 2         ----	*/
	/*	---- Conic built from 5 tangents ---- 	*/
	
	if (choix == 2) {
		try {
			ConicClass::Conic conique2;
			
	  		conique2.addPointsToConic(listePoints, nombreDePoints, viewer);
			
			conique2.display(viewer);
		}
		catch (std::invalid_argument e) {
			std::cerr << "Ajoutez davantage de points à la conique" << std::endl;
		}
	}
	
	/*	---- 	           EXAMPLE 3    	 ----	*/
	/*	---- Conic built from more than 5 points ----	*/
	
	if (choix == 3) {
		ConicClass::Conic conique3;
		
		for (long unsigned int i = 0; i < 2*nombreDePoints; ++i) {
			Eigen::VectorXd point(2);
			point << distrib(generator), distrib(generator);

	    		assert(point.size() == 2 && "Erreur dans la définition des coordonnées des points");

			listePoints.push_back(point);
			conique3.addPoint(point.transpose());
			std::string nom = "pt" + std::to_string(i+1);
			viewer.push_point(listePoints[i].transpose(), nom, 200,0,0);
		}

	  	assert(conique3.getPoints().size() == 2*nombreDePoints && "Erreur dans l'enregistrement des points.");

	  	if (nombreDePoints < 5) {
			throw std::invalid_argument("Il n'y a pas suffisamment de points pour construire une conique.");
		}
		
		conique3.display(viewer);
	}

	// render
	viewer.display(); // on terminal
	viewer.render("output.html");  // generate the output file (to open with your web browser)

	return 0;
}
