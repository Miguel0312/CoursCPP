/*************************************************************************
                           TrajetSimple -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined (TRAJET_SIMPLE_H)
#define TRAJET_SIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Sous-classe de Trajet qui implémente un trajet qui est completement
// caracterisé par une ville de départ, une ville d'arrivée et un
// moyen de transport
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  
char * GetTransport() const;

virtual void Affichage() const override;
// Mode d'emploi :
// Affiche la ville de depart, la ville d'arrivée et le moyen de transport
// du trajet

virtual void Sauvegarder(ofstream& destin) const override;

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple(const char* d, const char* a, const char* t);
// Mode d'emploi :
// Construit le TrajetSimple étant donnés les villes de départ et d'arrivée
// ainsi que le moyen de transport

virtual ~TrajetSimple ( );
// Mode d'emploi :
// Destructeur de TrajetSimple

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
  char* transport;
};

#endif // TRAJET_SIMPLE_H
