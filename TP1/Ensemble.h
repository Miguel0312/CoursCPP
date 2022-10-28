#pragma once

#define CARD_MAX 5

// Ensemble gére une collection d'entiers de taille quelconque
// L'implementation correspond à un ensemble mathématique
// Les élements sont sauvergadés de manière strictement croissante dans tableau

enum crduEstInclus{
	NON_INCLUSION,
	INCLUSION_LARGE,
	INCLUSION_STRICTE
};

class Ensemble{
private:
	//Attributs privés
	unsigned int cardMax;
	unsigned int cardActuelle;
	int* tableau;

public:
	// Constructeurs
	Ensemble(unsigned int pCardMax = CARD_MAX);
	// Crée un Ensemble vide qui peut contenir jusqu'à pCardMax élements

	Ensemble(int t[], unsigned int nbElements);
	// Crée un Ensemble qui peut contenir jusqu'à nbElements élements
	// Ajoute les nbElements premiers élements de t au tableau,
	// tout en respectant la définition mathématique d'un ensemble
	// (pas d'élements repetés)

	// Destructeur
	virtual ~Ensemble(void);

	//Méthodes
	void Afficher(void);
	// Affiche dans la première ligne le nombre d'élements dans l'ensemble
	// Dans la deuxième, affiche la cardinalité maximale
	// Dans la troisième, affiche tous les élements de l'ensemble en ordre croissante

	bool EstEgal(const Ensemble & unEnsemble);
	// Compare si tous les élements de cet ensemble est dans unEnsemble
	// et vice-versa. Si oui, retourne true

	crduEstInclus EstInclus(const Ensemble & unEnsemble);
	// Si les ensembles sont égaux, renvoie INCLUSION_LARGE
	// Si tous les élements du premier sont dans le deuxième,
	// mais ils ne sont pas égaux renvoie INCLUSION_STRICTE
	// S'il y a un élement du premier n'est pas dans le deuxième,
	// renvoie NON_INCLUSION
};