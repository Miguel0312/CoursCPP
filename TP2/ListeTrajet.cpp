/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajet> (fichier ListeTrajet.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Node.h"
#include "Trajet.h"
#include "ListeTrajet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ListeTrajet::AjouterTrajet(const Trajet* const newT)
// Algorithme:
// Ajoute un nouveau élement au début de la liste et met ce nouveau élement
// comme nouveau début de la liste
{
    // Met la taille de la liste à jour
    taille++;
    Node* newHead = new Node;
    newHead->SetTrajet(newT);
    newHead->SetNext(head);
    head = newHead;
} //----- Fin de AjouterTrajet

void ListeTrajet::AjouterTrajetFin(const Trajet* const newT)
// Algorithme:
// Parcourt toute la liste et ajoute un nouveau élement à la fin
{
    taille++;
    Node* tail = new Node;
    tail->SetTrajet(newT);
    tail->SetNext(nullptr);
    // Si la liste est vide, l'élement inseré est aussi le nouveau début
    if(head == nullptr){
        head = tail;
        return;
    }
    Node* cur = head;
    // Parcourt la liste jusqu'à la fin
    while(cur->GetNext()!=nullptr){
        cur = cur->GetNext(); 
    }
    cur->SetNext(tail);
} //----- Fin de AjouterTrajetFin

void ListeTrajet::Affichage(){
    Node* cur = head;
    while(cur != nullptr){
        cur->GetTrajet()->Affichage();
        cur = cur->GetNext();
    }
} //----- Fin de Affichage

void ListeTrajet::EnleverFin()
// Algorithme:
// Parcourt la liste jusqu'à la fin et enlève le dernier élement de la liste
// Fait aussi la mise à jour de l'élement suivant ce qui est maintenant le
// dernier élement
{
    // Si la liste est vide, on ne fait rien
    if(head == nullptr)
        return;
    // Si la liste n'a qu'un élement, il faut affecter le début de la liste à
    // un nullptr
    if(head->GetNext() == nullptr){
        taille--;
        delete head;
        head = nullptr;
        return;
    }

    Node* tail = head;
    // Parcourt la liste jusqu'à la find
    while(tail->GetNext()->GetNext() != nullptr){
        tail = tail->GetNext();
    }

    // Enlève le dernier élement
    delete tail->GetNext();
    tail->SetNext(nullptr);
    taille--;
} //----- Fin de EnleverFin

Node* ListeTrajet::GetHead() const{
    return head;
} //----- Fin de GetHead

int ListeTrajet::GetTaille() const{
    return taille;
} //----- Fin de GetTaille

//-------------------------------------------- Constructeurs - destructeur

ListeTrajet::ListeTrajet() :
head(nullptr), taille(0)
// Algorithme :
// Affecte le début de la liste à un nullptr et met la taille à 0, car il n'y a
// pas d'élements
{
#ifdef MAP
    cout << "Appel au constructeur de ListeTrajet" << endl;
#endif
} //----- Fin de ListeTrajet

ListeTrajet::~ListeTrajet()
// Algorithme :
// Parcourt la liste entière et delete les noeuds qui la composent
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajet>" << endl;
#endif
    while(head!=nullptr){
        Node* n = head;
        head = head->GetNext();
        delete n;
    }
} //----- Fin de ~ListeTrajet