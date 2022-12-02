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
char * TrajetSimple::getTransport() const{
    return transport;
}

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


TrajetSimple::TrajetSimple (const TrajetSimple& t) :
TrajetSimple(t.getDepart(), t.getArrivee(), t.getTransport())
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif

} //----- Fin de TrajetSimple (constructeur de copie)

TrajetSimple::TrajetSimple (const char* d, const char* a, const char* t) :
Trajet(d, a)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de TrajetSimple" << endl;
#endif

    transport = new char[strlen(t)+1];
    strcpy(transport, t);
} //----- Fin de TrajetSimple (constructeur)

TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
    delete[] transport;
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

