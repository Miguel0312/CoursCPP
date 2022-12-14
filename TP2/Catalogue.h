/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if !defined (CATALOGUE_H)
#define CATALOGUE_H

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

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  void AjouterTrajet(const Trajet* t);
  // Mode d'emploi :
  //
  // Contrat :
  //

  bool RechercheSimple(const char* depart, const char* arrivee) const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  bool RechercheAvancee(const char* depart, const char* arrivee) const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  bool DFS(const char* const depart,
         const char* const arrivee, bool* visited,
         ListeTrajet& cheminActuel, int n, int& m) const;

  void Affichage() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

//-------------------------------------------- Constructeurs - destructeur
  Catalogue();
  // Mode d'emploi (constructeur de copie) :
  //
  // Contrat :
  //

  virtual ~Catalogue();
  // Mode d'emploi :
  //
  // Contrat :
  //

//------------------------------------------------------------------ PRIVE
private:
  ListeTrajet trajets;

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
