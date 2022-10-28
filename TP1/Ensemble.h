#pragma once
#include <iostream>
#define CARD_MAX 5

class Ensemble{
private:
	unsigned int cardMax;
	unsigned int cardActuelle;
	int* tableau;

public:
	Ensemble(unsigned int pCardMax = CARD_MAX);
	Ensemble(int t[], unsigned int nbElements);

	virtual ~Ensemble(void);
	void Afficher(void);
};