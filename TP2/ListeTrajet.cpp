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
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Node.h"
#include "Trajet.h"
#include "ListeTrajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ListeTrajet::ajouterTrajet(const Trajet* const newT){
    taille++;
    Node* newHead = new Node;
    newHead->setTrajet(newT);
    newHead->setNext(head);
    head = newHead;
}

void ListeTrajet::ajouterTrajetFin(const Trajet* const newT){
    taille++;
    Node* tail = new Node;
    tail->setTrajet(newT);
    tail->setNext(nullptr);
    if(head == nullptr){
        head = tail;
        return;
    }
    Node* cur = head;
    while(cur->getNext()!=nullptr){
        cur = cur->getNext(); 
    }
    cur->setNext(tail);
}

Node* ListeTrajet::getHead() const{
    return head;
}

int ListeTrajet::getTaille() const{
    return taille;
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
head(nullptr), taille(0)
{
#ifdef MAP
    cout << "Appel au constructeur de ListeTrajet" << endl;
#endif
} //----- Fin de ListeTrajet

ListeTrajet::~ListeTrajet()
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajet>" << endl;
#endif
    while(head!=nullptr){
        Node* n = head;
        head = head->getNext();
        delete n;
    }
} //----- Fin de ~ListeTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées