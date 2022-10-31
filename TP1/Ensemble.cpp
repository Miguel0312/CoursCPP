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
	int s[nbElements];
	for(int i = 0; i < nbElements; i++)
		s[i] = t[i];
	// Met les nbElements premiers élements de t en ordre croissante
	// en utilisant un insertion sort
	// En suite met les élements dans l'ensemble sans prendre les repetés
	for(int i = 0; i+1 < nbElements; i++){
		int m = s[i], index = i;
		for(int j = i+1; j < nbElements; j++){
			if(s[j] < m){
				m = s[j];
				index = j;
			}
		}
		int tmp = s[i];
		s[i] = s[index];
		s[index] = tmp;
	}

	cardActuelle = 0;
	tableau = new int[nbElements];

	for(int i = 0; i < nbElements; i++){
		if(i == nbElements - 1 || s[i] != s[i+1]){
			tableau[cardActuelle] = s[i];
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

bool Ensemble::EstEgal(const Ensemble & unEnsemble) const{
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

crduEstInclus Ensemble::EstInclus(const Ensemble & unEnsemble) const{
	// Si les deux ensembles sont égaux, on a l'inclusion large
	if(this->EstEgal(unEnsemble))
		return INCLUSION_LARGE;

	// Si le premier ensemble a plus d'élements, il ne peut pas être inclus
	if(cardActuelle > unEnsemble.cardMax)
		return NON_INCLUSION;

	// On vérifie que chaque élement dans le premier ensemble est présent dans le deuxième
	for(int i = 0; i < cardActuelle; i++){
		bool found = false;
		for(int j = 0; j < unEnsemble.cardActuelle; j++){
			if(unEnsemble.tableau[j] == tableau[i]){
				found = true;
				break;
			}
		}
		if(!found)
			return NON_INCLUSION;
	}

	return INCLUSION_STRICTE;
}

crduAjouter Ensemble::Ajouter(int aAjouter){
	for(int i = 0; i < cardActuelle; i++)
		if(tableau[i] == aAjouter)
			return DEJA_PRESENT;

	if(cardActuelle == cardMax)
		return PLEIN;

	int index = 0;
	for(int i = 0; i < cardActuelle; i++){
		if(aAjouter > tableau[i])
			index++;
		else
			break;
	}

	for(int i = cardActuelle - 1; i >= index; i--){
		tableau[i+1] = tableau[i];
	}

	tableau[index] = aAjouter;
	cardActuelle++;
	return AJOUTE;
}

unsigned int Ensemble::Ajuster(int delta){
	if(delta == 0)
		return cardMax;

	if(delta > 0){
		cardMax += delta;
	} else if(delta < 0){
		cardMax = cardActuelle > cardMax + delta ? cardActuelle : cardMax + delta;
	}
	int * nTableau = new int[cardMax];
	for(int i = 0; i < cardActuelle; i++){
		nTableau[i] = tableau[i];
	}
	delete tableau;
	tableau = nTableau;
	return cardMax;
}

bool Ensemble::Retirer(int element){
	unsigned int index = cardMax+1;
	for(unsigned int i = 0; i < cardActuelle; i++){
		if(tableau[i] == element){
			index = i;
			break;
		}
	}

	if(index == cardMax+1){
		Ajuster(-cardMax);
		return false;
	}

	for(unsigned int i = index; i+1 < cardActuelle; i++)
		tableau[i] = tableau[i+1];

	cardActuelle--;

	Ajuster(-cardMax);
	return true;
}

unsigned int Ensemble::Retirer(const Ensemble & unEnsemble){
	unsigned int ans = 0;
	int s[unEnsemble.cardActuelle];
	unsigned int size = unEnsemble.cardActuelle;
	for(int j = 0; j < unEnsemble.cardActuelle; j++){
		s[j] = unEnsemble.tableau[j];
	}
	for(unsigned int j = 0; j < size; j++){
		unsigned int index = cardMax+1;
		for(unsigned int i = 0; i < cardActuelle; i++){
			if(tableau[i] == s[j]){
				index = i;
				break;
			}
		}

		if(index == cardMax+1){
			continue;
		}

		for(unsigned int i = index; i+1 < cardActuelle; i++)
			tableau[i] = tableau[i+1];

		cardActuelle--;
		ans++;
	}

	return ans;
}

int Ensemble::Reunir(const Ensemble & unEnsemble){
	int ans = 0;

	int * newTableau = new int[cardActuelle+unEnsemble.cardActuelle];
	for(int i = 0; i < cardActuelle; i++)
		newTableau[i] = tableau[i];
	int newSize = cardActuelle;

	for(int j = 0; j < unEnsemble.cardActuelle; j++){
		int aAjouter = unEnsemble.tableau[j];
		bool found = false;
		for(int i = 0; i < cardActuelle && !found; i++)
			if(tableau[i] == aAjouter)
				found = true;

		if(found)
			continue;

		int index = 0;
		for(int i = 0; i < newSize; i++){
			if(aAjouter > newTableau[i])
				index++;
			else
				break;
		}

		for(int i = newSize - 1; i >= index; i--){
			newTableau[i+1] = newTableau[i];
		}

		newTableau[index] = aAjouter;
		newSize++;
		ans++;
	}

	delete tableau;
	tableau = newTableau;

	cardActuelle = newSize;
	if(newSize <= cardMax)
		return ans;
	else{
		cardMax = newSize;
		return -ans;
	}
}

unsigned int Ensemble::Intersection(const Ensemble & unEnsemble){
	unsigned int ans = 0;
	int s[unEnsemble.cardActuelle];
	unsigned int size = unEnsemble.cardActuelle;
	for(int j = 0; j < unEnsemble.cardActuelle; j++){
		s[j] = unEnsemble.tableau[j];
	}

	for(int i = 0; i < cardActuelle; i++){
		bool found = false;
		for(int j = 0; j < size && !found; j++)
			if(s[j] == tableau[i])
				found = true;

		if(!found){
			Retirer(tableau[i]);
			i--;
			ans++;
		}
	}
	
	Ajuster(-cardMax);

	return ans;
}