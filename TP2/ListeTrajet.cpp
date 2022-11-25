/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Node.h"
#include "Trajet.h"
#include "ListeTrajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ListeTrajet::ajouterTrajet(Trajet* newT){
    Node* newHead = new Node;
    newHead->setTrajet(newT);
    newHead->setNext(head);
    head = newHead;
}

//-------------------------------------------- Constructeurs - destructeur
/*Xxx::Xxx ( const Xxx & unXxx )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)
*/

ListeTrajet::ListeTrajet() :
head(nullptr)
{
#ifdef MAP
    cout << "Appel au constructeur de ListeTrajet" << endl;
#endif
} //----- Fin de ListeTrajet

ListeTrajet::~ListeTrajet()
{
    while(head!=nullptr){
        Node* n = head;
        head = head->getNext();
        delete n->getTrajet();
        delete n;
    }
#ifdef MAP
    cout << "Appel au destructeur de ListeTrajet" << endl;
#endif
} //----- Fin de ~ListeTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées