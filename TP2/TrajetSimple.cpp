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

#include "Trajet.h"

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Affichage() const{
    cout<<"De "<<depart<<" a "<<arrivee<<" en "<<transport<<"\n";
}


//------------------------------------------------- Surcharge d'opérateurs
/*Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (const char* d, const char* a, const char* t)
// Algorithme :
//
{
    depart = new char(strlen(d)+1);
    arrivee = new char(strlen(a)+1);
    transport = new char(strlen(t)+1);
    strcpy(depart, d);
    strcpy(arrivee, a);
    strcpy(transport, t);

#ifdef MAP
    cout << "Appel au constructeur de TrajetSimple" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)

TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
    delete depart;
    delete arrivee;
    delete transport;
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

