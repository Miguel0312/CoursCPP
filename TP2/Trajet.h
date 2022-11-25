/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if !defined (TRAJET_H)
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  virtual void Affichage() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

//-------------------------------------------- Constructeurs - destructeur
    virtual ~Trajet();
    // Mode d'emploi :
    //
    // Contrat :
    //*/

//-------------------------------------------------------------- PROTECTED
protected:
//----------------------------------------------------- Attributs protégés
  char * depart;
  char * arrivee;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
