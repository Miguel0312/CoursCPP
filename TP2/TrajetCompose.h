/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) -----
#if ! defined (TRAJET_COMPOSE_H)
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajet.h"
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------------------
// Sous-classe de Trajet qui implémente un trajet composé par differents trajets
// Ce trajet est encore traité de manière atomique, c'est à dire que la
// personne doit parcourir le trajet du tout début jusqu'à la fin, il n'est 
// pas possible de sortir au milieu.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  virtual void Affichage() const;
  // Mode d'emploi :
  // Affiche par combien de trajets ce trajet est composé et fait aussi
  // l'affichage de chacun de ces trajets

  bool AjouterTrajet(Trajet* t);
  // Mode d'emploi :
  // Si le trajet à ajouter a la même ville de départ que la ville d'arrivée du
  // TrajetCompose actuel, ajoute t à la fin du trajet. Sinon, affiche une erreur
  // Renvoie vrai si et seulement si le trajet a été ajouté

//-------------------------------------------- Constructeurs - destructeur
  TrajetCompose();
  // Mode d'emploi :
  // Construit un nouveau TrajetCompose vide

  virtual ~TrajetCompose();
  // Mode d'emploi :
  // Détruit le trajet composé ainsi que les trajets qui le composent

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
  ListeTrajet trajets;
};


#endif // TRAJET_COMPOSE_H
