/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined (TRAJET_SIMPLE_H)
#define TRAJET_SIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
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
  TrajetSimple(const char* d, const char* a, const char* t);
  // Mode d'emploi :
  //
  // Contrat :
  //
  
  virtual ~TrajetSimple ( );
  // Mode d'emploi :
  //
  // Contrat :
  //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  char* transport;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
