#include <stdio.h>
#include "Ensemble.h"

static void testConstructeur1(){
	Ensemble ens;
	ens.Afficher();
}

static void testConstructeur2(){
	Ensemble ens(10);
	ens.Afficher();
}

static void testConstructeur3(){
	int t[] = {3, 3, 4 , 5, 2, 2, 1};
	Ensemble ens(t, 7);
	ens.Afficher();
}

int main(){
	testConstructeur3();
	return 0;
}