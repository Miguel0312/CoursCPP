/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include<cstring>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

char* Trajet::GetDepart() const{
  return depart;
} //----- Fin de GetDepart

char* Trajet::GetArrivee() const{
  return arrivee;
} //----- Fin de GetArrivee


//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet():
depart(nullptr), arrivee(nullptr)
{
#ifdef MAP
  cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet


Trajet::~Trajet()
{
#ifdef MAP
  cout << "Appel au destructeur de <Trajet>" << endl;
#endif
    delete[] depart;
    delete[] arrivee;
} //----- Fin de ~Trajet

