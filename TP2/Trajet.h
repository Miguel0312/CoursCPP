/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if !defined (TRAJET_H)
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>

//------------------------------------------------------------------------
// Classe abstraite qui est super-classe de trajet simple et trajet composé
//  Établit les points communs entre ces deux classes: ville de départ et
//  d'arrivée ainsi qu'une méthode d'affichage
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  virtual void Affichage() const = 0;
  // Méthode virutel pure -> Rend cette classe abstraite (ne peut pas être
  // instantiée)

  char* GetDepart() const;
  // Mode d'emploi :
  // Renvoie le nom de la ville de départ

  char* GetArrivee() const;
  // Mode d'emploi :
  // Renvoie le nom de la ville d'arrivée

   virtual void Sauvegarder(ofstream& destin) const = 0;
   // Mode d'emploi :
  // Encode le trajet et l'écrive dans la stream destin

//-------------------------------------------- Constructeurs - destructeur
  Trajet();

  virtual ~Trajet();

//-------------------------------------------------------------- PROTECTED
protected:
//----------------------------------------------------- Attributs protégés
  char * depart;
  char * arrivee;
};

#endif // TRAJET_H
