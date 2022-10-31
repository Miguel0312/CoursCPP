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

enum crduAjouter{
	DEJA_PRESENT,
	PLEIN,
	AJOUTE
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

	bool EstEgal(const Ensemble & unEnsemble) const;
	// Compare si tous les élements de cet ensemble est dans unEnsemble
	// et vice-versa. Si oui, retourne true

	crduEstInclus EstInclus(const Ensemble & unEnsemble) const;
	// Si les ensembles sont égaux, renvoie INCLUSION_LARGE
	// Si tous les élements du premier sont dans le deuxième,
	// mais ils ne sont pas égaux renvoie INCLUSION_STRICTE
	// S'il y a un élement du premier n'est pas dans le deuxième,
	// renvoie NON_INCLUSION

	crduAjouter Ajouter(int aAjouter);
	// Renvoie DEJA_PRESENT si aAjouter est déjà présent
	// Sinon, renvoie PLEIN si le tableau est plein
	// Sinon, ajoute l'élement est renvoie AJOUTE

	unsigned int Ajuster(int delta);
	// Si delta>=0, augmente cardMax de delta
	// Si delta<0, diminue cardMax au maximum de delta, sans perdre d'élements
	// Renvoie la nouvelle cardMax

	bool Retirer(int element);
	// Retire element de l'ensemble
	// Renvoie true s'il était présent, false sinon
	// Il change cardMax pour qu'elle soit égale à cardActuelle après la suppression

	unsigned int Retirer(const Ensemble & unEnsemble);
	// Retire tous les élements de unEnsemble qui sont dans l'ensemble actuel
	// Renvoie le nombre d'élements supprimés
	// Il ne chage pas cardMax

	int Reunir(const Ensemble & unEnsemble);
	// Ajoute tous les élements d'unEnsemble a cet ensemble
	// Renvoie le nombre dont la valeur absolue est égal au nombre d'élements
	// effectivement rajoutés.
	// Il est positif si cardMax n'a pas changé, négatif sinon

	unsigned int Intersection(const Ensemble & unEnsemble);
	// Rend cet ensemble égal l'intersection entre les deux ensembles
	// Rend cardMax = cardActuelle
	// Renvoie le nobre d'élement supprimés
};