/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//---------- Interface de la classe <Node> (fichier Node.h) ----------------
#if ! defined ( NODE_H )
#define NODE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <Node>
// Classe utilisé par ListeChaînée qui contient un trajet et un pointeur
//  vers le prochain noeud de la liste
//------------------------------------------------------------------------

class Node
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    const Trajet* GetTrajet() const;
    // Mode d'emploi : 
    // Renvoie un pointeur vers le trajet contenu par ce noeud

    Node* GetNext() const;
    // Mode d'emploi : 
    // Renvoie un pointeur vers le noeud suivant

    void SetTrajet(const Trajet* newT);
    // Mode d'emploi : 
    // Change le trajet contenu par ce noeud

    void SetNext(Node* nextNode);
    // Mode d'emploi :
    // Change le noeud suivant pointé par ce noeud

//-------------------------------------------- Constructeurs - destructeur
    Node();
    // Mode d'emploi :
    // Crée un nouveau noeud avec le trajet et le noeud suivaint égaux à 
    // nullptr

    virtual ~Node ( );
    // Mode d'emploi :
    // Destructeur de Node

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Attributs privés
    const Trajet* t;
    Node* next;
};

#endif // NODE_H
