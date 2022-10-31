#include <iostream>
#include "Ensemble.h"

static void testConstructeur1(){
	Ensemble ens;
	ens.Afficher();
}

static void testConstructeur2(){
	Ensemble ens(0);
	ens.Afficher();
}

static void testConstructeur3(){
	int t[] = {3, 3, 4 , 5, 2, 2, 1};
	Ensemble ens(t, 7);
	ens.Afficher();
}

static void testEstEgal(){
	int t1[] = {3, 3, 4 , 5, 2, 2, 1};
	int t2[] = {1, 2, 3, 4, 4};

	Ensemble ens1(t1, 7);
	Ensemble ens2(t2, 5);
	
	if(ens1.EstEgal(ens2))
		std::cout << "Égaux" << std::endl;
	else
		std::cout << "Différents" << std::endl;
}

static void testInclusion(){
	int t1[] = {3, 3, 4 , 5, 2, 2, 1};
	int t2[] = {1, 2, 3, 4, 4};

	Ensemble ens1(t2, 5);
	Ensemble ens2(t1, 7);
	
	if(ens1.EstInclus(ens2) == crduEstInclus::INCLUSION_STRICTE)
		std::cout << "Est inclus" << std::endl;
	else if(ens1.EstInclus(ens2) == crduEstInclus::NON_INCLUSION)
		std::cout << "N'est pas inclus" << std::endl;
}

static void testAjout(){
	int t1[] = {3, 3, 4 , 5, 2, 1};
	Ensemble ens(t1, 6);

	std::cout << ens.Ajouter(4) << std::endl;
	std::cout << ens.Ajouter(7) << std::endl;
	std::cout << ens.Ajouter(10) << std::endl;
}

static void testAjuster(){
	int t1[] = {3, 3, 4 , 5, 2, 1};
	Ensemble ens(t1, 6);
	ens.Ajuster(4);
	ens.Afficher();
	ens.Ajuster(-4);
	ens.Afficher();
	ens.Ajuster(-4);
	ens.Afficher();
}

static void testRetirer1(){
	int t1[] = {3, 3, 4 , 5, 2, 1};
	Ensemble ens(t1, 6);
	std::cout << ens.Retirer(10) << std::endl;
	ens.Afficher();
}

static void testRetirer2(){
	int t1[] = {3, 3, 4 , 5, 2, 2, 1};
	int t2[] = {1, 2, 3, 4, 4};

	Ensemble ens1(t1, 7);
	Ensemble ens2(t2, 5);

	std::cout << ens2.Retirer(ens2) << std::endl;
	ens2.Afficher();
}

static void testReunir(){
	int t1[] = {1, 2, 3};
	int t2[] = {6, 7, 3};

	Ensemble ens1(t1, 3);
	Ensemble ens2(t2, 3);

	std::cout << ens1.Reunir(ens2) << std::endl;
	ens1.Afficher();
	std::cout << ens2.Reunir(ens2) << std::endl;
	ens2.Afficher();
}

static void testIntersection(){
	int t1[] = {-4, -2, 0, 2, 77, 0, 0, 0, 0};
	int t2[] = {-4, -2, 0, 1, 2, 77};

	Ensemble ens1(t1, 9);
	Ensemble ens2(t2, 6);
	ens1.Afficher();
	std::cout << ens1.EstEgal(ens2) << std::endl;
	ens1.Intersection(ens2);
	ens1.Afficher();
}

int main(){
	testIntersection();
	return 0;
}