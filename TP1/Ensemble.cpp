#include "Ensemble.h"

Ensemble::Ensemble(unsigned int pCardMax):
cardMax(pCardMax){
	cardActuelle = 0;
	tableau = new int[cardMax];
}

Ensemble::Ensemble(int t[], unsigned int nbElements):
cardMax(nbElements){
	for(int i = 0; i < nbElements-1; i++){
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

	for(int i = 0; i < nbElements; i++){
		if(i == nbElements - 1 || t[i] != t[i+1]){
			cardActuelle++;
		}
	}

	tableau = new int[cardActuelle];

	int index = 0;
	for(int i = 0; i < nbElements; i++){
		if(i == nbElements - 1 || t[i] != t[i+1]){
			tableau[index] = t[i];
			index++;
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