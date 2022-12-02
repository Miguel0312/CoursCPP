/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Node.h"
#include "ListeTrajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AjouterTrajet(const Trajet* t)
// Algorithme :
//
{
    trajets.ajouterTrajet(t);
}

void Catalogue::RechercheSimple(const char* depart, const char* arrivee) const
// Algorithme :
//
{
    
}

void Catalogue::Affichage() const{
    Node* cur = trajets.getHead();
    while(cur != nullptr){
        cur->getTrajet()->Affichage();
        cur = cur->getNext();
    }
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue() :
trajets(ListeTrajet())
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de Catalogue" << endl;
    #endif
} //----- Fin de Catalogue (constructeur de copie)

Catalogue::~Catalogue()
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <Xxx>" << endl;
    #endif
} //----- Fin de ~Xxx*/


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
