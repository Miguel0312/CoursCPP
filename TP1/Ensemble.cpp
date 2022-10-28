#include <iostream>
#include "Ensemble.h"

Ensemble::Ensemble(unsigned int pCardMax):
cardMax(pCardMax){
	cardActuelle = 0;
	if(pCardMax != 0)
		tableau = new int[cardMax];
	else
		tableau = NULL;
}

Ensemble::Ensemble(int t[], unsigned int nbElements):
cardMax(nbElements){
	// Met les nbElements premiers élements de t en ordre croissante
	// en utilisant un insertion sort
	// En suite met les élements dans l'ensemble sans prendre les repetés
	for(int i = 0; i+1 < nbElements; i++){
		int m = t[i], index = i;
		for(int j = i+1; j < nbElements; j++){
			if(t[j] < m){
				m = t[j];
				index = j;
			}
		}
		int tmp = t[i];
		t[i] = t[index];
		t[index] = tmp;
	}

	cardActuelle = 0;
	tableau = new int[nbElements];

	for(int i = 0; i < nbElements; i++){
		if(i == nbElements - 1 || t[i] != t[i+1]){
			tableau[cardActuelle] = t[i];
			cardActuelle++;
		}
	}
}

Ensemble::~Ensemble(void){
	delete tableau;
}

void Ensemble::Afficher(void){
	std::cout << cardActuelle << "\r\n" << cardMax << "\r\n";
	std::cout << "{";
	for(int i = 0; i < cardActuelle; i++){
		std::cout << tableau[i];
		if(i != cardActuelle - 1)
				std::cout << ',';
	}
	std::cout << "}\r\n";
}

bool Ensemble::EstEgal(const Ensemble & unEnsemble){
	// Si les ensembles ont un nombre différent d'élements, ils ne peuvent pas être égaux
	// On utilise le fait que les élements dans les tableaux sont triés de manière croissante
	// Alors, le ième élement de tableau doit correspondre à l'ième élement de tableau2
	// pour qu'ils soient égaux
	if(cardActuelle != unEnsemble.cardActuelle)
		return false;

	for(int i = 0; i < cardActuelle; i++){
		if(tableau[i] != unEnsemble.tableau[i])
			return false;
	}

	return true;
}

crduEstInclus Ensemble::EstInclus(const Ensemble & unEnsemble){
	if(this->EstEgal(unEnsemble))
		return crduEstInclus::INCLUSION_LARGE;

	if(cardActuelle > unEnsemble.cardMax)
		return crduEstInclus::NON_INCLUSION;

	for(int i = 0; i < cardActuelle; i++){
		bool found = false;
		for(int j = 0; j < unEnsemble.cardActuelle; j++){
			if(unEnsemble.tableau[j] == tableau[i]){
				found = true;
				break;
			}
		}
		if(!found)
			return crduEstInclus::NON_INCLUSION;
	}

	return crduEstInclus::INCLUSION_STRICTE;
}