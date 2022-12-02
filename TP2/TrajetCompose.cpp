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
#include<cstring>

//------------------------------------------------------ Include personnel
#include "Node.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Affichage() const
// Algorithme :
//
{
    int nbTrajets = 0;
    Node* current = trajets.getHead();
    while(current !=nullptr){
        nbTrajets++;
    }
    cout<<"Trajet compose avec "<<nbTrajets<<" trajets simples.\n";
    Node* head = trajets.getHead();
    while(head!=nullptr){
        head->getTrajet()->Affichage();
        head = head->getNext();
    }
} //----- Fin de Méthode

void TrajetCompose::AjouterTrajet(TrajetSimple t){
    
    if(trajets.getHead() == nullptr){
        char* tDepart = t.getDepart();
        depart = new char[strlen(tDepart)+1];
        strcpy(depart, tDepart);
        depart = t.getDepart();
    }
    if(arrivee!=nullptr){
        delete[] arrivee;
    }
    char* tArrivee = t.getArrivee();
    arrivee = new char[strlen(tArrivee)+1];
    strcpy(arrivee, tArrivee);

    TrajetSimple* tCopy = new TrajetSimple(t);
    trajets.ajouterTrajetFin(tCopy);
}


//------------------------------------------------- Surcharge d'opérateurs
/*Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de TrajetSimple

TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
    Node* cur = trajets.getHead();
    while(cur!=nullptr){
        delete cur->getTrajet();
        cur = cur->getNext();
    }
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

