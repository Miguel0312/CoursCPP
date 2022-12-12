/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined ( LISTE_TRAJET_H )
#define LISTE_TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include "Node.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class ListeTrajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void ajouterTrajet(const Trajet* const newT);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void ajouterTrajetFin(const Trajet* const newT);

    void Affichage();

    void EnleverFin();

    Node* getHead() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    int getTaille() const;


//-------------------------------------------- Constructeurs - destructeur
    ListeTrajet();
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ~ListeTrajet();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
private:
    Node* head;
    int taille;

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H