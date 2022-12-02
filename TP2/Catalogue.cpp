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
    ListeTrajet chemins;
    Node* cur = trajets.getHead();

    while(cur != nullptr){
        if(strcmp(depart, cur->getTrajet()->getDepart()) == 0 &&
           strcmp(arrivee, cur->getTrajet()->getArrivee()) == 0){
            chemins.ajouterTrajet(cur->getTrajet());
           }
        cur = cur->getNext();
    }

    cout << "Chemins possibles entre " << depart << " et " << arrivee << endl;
    cur = chemins.getHead();
    int n = 1;
    while(cur != nullptr){
        cout << n++ << ") ";
        cur->getTrajet()->Affichage();
        cur = cur->getNext();
        if(cur != nullptr)
            printf("\r\n");
    }
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
} //----- Fin du constructeur de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue*/


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
