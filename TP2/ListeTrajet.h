/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//---------- Interface de la classe <ListeTrajet> (fichier ListeTrajet.h) ------
#if ! defined ( LISTE_TRAJET_H )
#define LISTE_TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include "Node.h"
#include "Trajet.h"

//------------------------------------------------------------------------
// Classe qui implémente une liste chaînée de trajets
//------------------------------------------------------------------------

class ListeTrajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterTrajet(const Trajet* const newT);
    // Mode d'emploi :
    // Ajoute un trajet au début de la liste

    void AjouterTrajetFin(const Trajet* const newT);
    // Mode d'emploi :
    // Ajoute un trajet à la fin de la liste

    void Affichage();
    // Mode d'emploi :
    // Affiche chaque trajet de la liste

    void EnleverFin();
    // Mode d'emploi :
    // Enlève le dernier trajet de la liste

    Node* GetHead() const;
    // Mode d'emploi :
    // Renvoie le premier noeud de la liste

    int GetTaille() const;
    // Mode d'emploi :
    // Renvoie le nombre d'élements de la liste


//-------------------------------------------- Constructeurs - destructeur
    ListeTrajet();
    // Mode d'emploi :
    // Construit une nouvelle liste vide

    ~ListeTrajet();
    // Mode d'emploi :
    // Destruit la liste et tous le noeuds qui la composent

//------------------------------------------------------------------ PRIVE
private:
//----------------------------------------------------- Attributs privés
    Node* head; // Premier élement de la liste
    int taille; // Nombre d'élements de la liste

};

#endif // LISTE_TRAJET_H