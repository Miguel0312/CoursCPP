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
#include "Catalogue.h"
#include "Node.h"
#include "ListeTrajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AjouterTrajet(const Trajet* t)
// Algorithme :
//
{
    trajets.ajouterTrajet(t);
}

bool Catalogue::RechercheSimple(const char* depart, const char* arrivee) const
// Algorithme :
//
{
    ListeTrajet chemins;
    Node* cur = trajets.getHead();

    while(cur != nullptr){
        if(strcmp(depart, cur->getTrajet()->getDepart()) == 0 &&
           strcmp(arrivee, cur->getTrajet()->getArrivee()) == 0){
            chemins.ajouterTrajet(cur->getTrajet());
           }
        cur = cur->getNext();
    }
    if(chemins.getHead()!= nullptr){
        cout << "Chemins possibles entre " << depart << " et " << arrivee << endl;
    }
    else{
        return false;
    }
    cur = chemins.getHead();
    int n = 1;
    while(cur != nullptr){
        cout << n++ << ") ";
        cur->getTrajet()->Affichage();
        cur = cur->getNext();
        if(cur != nullptr)
            printf("\r\n");
    }
    return true;
}

bool Catalogue::RechercheAvancee(const char* depart, const char* arrivee) const{
    cout << "Chemins possibles entre " << depart << " et " << arrivee
         << " (recherche avancee)" << endl;
    if(trajets.getTaille() == 0)
        return false;
    // Obtenir les noeuds
    int n = trajets.getTaille(), m = 1;
    
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;

    ListeTrajet cheminActuel;
    bool resultat = DFS(depart, arrivee, visited, cheminActuel, n, m);

    delete[] visited;

    return resultat;
}

bool Catalogue::DFS(const char* const depart,
         const char* const arrivee, bool* visited,
         ListeTrajet& cheminActuel, int n, int& m) const{
    if(strcmp(depart, arrivee) == 0){
        cout << m << ")" << endl;
        cheminActuel.Affichage();
        m++;
        return true;
    }

    Node* curNode = trajets.getHead();
    bool resultat = false;
    for(int j = 0; j < n; j++){
        if(!visited[j] && strcmp(depart, curNode->getTrajet()->getDepart()) == 0){
            visited[j] = true;
            cheminActuel.ajouterTrajetFin(curNode->getTrajet());
            resultat = DFS(curNode->getTrajet()->getArrivee(), arrivee, visited, cheminActuel, n, m) || resultat;
            cheminActuel.EnleverFin();
            visited[j] = false;
        }
        curNode = curNode->getNext();
    }

    return resultat;
}

void Catalogue::Affichage() const{
    Node* cur = trajets.getHead();
    while(cur != nullptr){
        cur->getTrajet()->Affichage();
        cur = cur->getNext();
    }
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue() :
trajets(ListeTrajet())
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de Catalogue" << endl;
#endif
} //----- Fin du constructeur de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue*/


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
