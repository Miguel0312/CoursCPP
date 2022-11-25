/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined (TRAJET_COMPOSE_H)
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajet.h"
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
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
  TrajetCompose(const unsigned int n, const char* d[], const char* a[], const char* t[]);
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  virtual ~TrajetCompose();
  // Mode d'emploi :
  //
  // Contrat :
  //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  ListeTrajet trajets;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
