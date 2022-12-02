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
#include<cstring>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::Affichage() const
//Algorithme :
//
{
} //----- Fin de Méthode

  char* Trajet::getDepart() const{
    return depart;
  }

  char* Trajet::getArrivee() const{
    return arrivee;
  }

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet():
depart(nullptr), arrivee(nullptr){}

Trajet::Trajet(const char* d, const char* a)
// Algorithme :
//
{
    depart = new char[strlen(d)+1];
    arrivee = new char[strlen(a)+1];
    strcpy(depart, d);
    strcpy(arrivee, a);
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Xxx


Trajet::~Trajet()
// Algorithme :
//
{
#ifdef MAP
  cout << "Appel au destructeur de <Trajet>" << endl;
#endif
    delete[] depart;
    delete[] arrivee;
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

