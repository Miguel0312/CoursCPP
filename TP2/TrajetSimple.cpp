/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//----- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) -----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include<cstring>
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
char * TrajetSimple::GetTransport() const{
    return transport;
} //----- Fin de GetTransport

void TrajetSimple::Affichage() const{
    cout<<"De "<<depart<<" a "<<arrivee<<" en "<<transport<<"\n";
} //----- Fin de Affichage

void TrajetSimple::Sauvegarder(ofstream& destin) const{
    destin << "S:" << depart << ':' << arrivee << ':'<< transport << '\n';
}


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (const char* d, const char* a, const char* t)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

    depart = new char[strlen(d)+1];
    arrivee = new char[strlen(a)+1];
    transport = new char[strlen(t)+1];
    strcpy(depart, d);
    strcpy(arrivee, a);
    strcpy(transport, t);
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
    delete[] transport;
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple

