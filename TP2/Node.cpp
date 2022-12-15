/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//---------- Réalisation de la classe <Node> (fichier Node.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Node.h"
#include "Trajet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const Trajet* Node::GetTrajet() const{
    return t;
} //----- Fin de GetTrajet

Node* Node::GetNext() const{
    return next;
} //----- Fin de GetNext

void Node::SetTrajet(const Trajet* newT){
    t = newT;
} //----- Fin de SetTrajet

void Node::SetNext(Node* nextNode){
    next = nextNode;
} //----- Fin de SetNext



//-------------------------------------------- Constructeurs - destructeur

Node::Node()
{
#ifdef MAP
    cout << "Appel au constructeur de <Node>" << endl;
#endif
} //----- Fin de Node


Node::~Node()
{
#ifdef MAP
    cout << "Appel au destructeur de <Node>" << endl;
#endif
} //----- Fin de ~Node