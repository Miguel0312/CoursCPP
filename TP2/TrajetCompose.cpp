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
    int nbTrajets = trajets.getTaille();
    cout<<"Trajet compose avec "<<nbTrajets<<" trajets simples.\n";
    Node* head = trajets.getHead();
    while(head!=nullptr){
        cout << "   ";
        head->getTrajet()->Affichage();
        head = head->getNext();
    }
} //----- Fin de Méthode

bool TrajetCompose::AjouterTrajet(TrajetSimple& t){
    
    if(trajets.getHead() == nullptr){
        char* tDepart = t.getDepart();
        depart = new char[strlen(tDepart)+1];
        strcpy(depart, tDepart);
    }
    else if(strcmp(arrivee, t.getDepart())){
        cout<<"ERREUR: le depart du chemin simple actuel doit etre egal a l'arrive du anterieur\n";
        return false;
    }
    if(arrivee!=nullptr){
        delete[] arrivee;
    }
    char* tArrivee = t.getArrivee();
    arrivee = new char[strlen(tArrivee)+1];
    strcpy(arrivee, tArrivee);

    TrajetSimple* tCopy = new TrajetSimple(t);
    trajets.ajouterTrajetFin(tCopy);
    return true;
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
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetSimple

TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

    Node* cur = trajets.getHead();
    while(cur!=nullptr){
        delete cur->getTrajet();
        cur = cur->getNext();
    }
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

