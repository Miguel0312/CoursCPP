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

int main(){
	testInclusion();
	return 0;
}