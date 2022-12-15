/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//----- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ---

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<cstring>

//------------------------------------------------------ Include personnel
#include "Node.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Affichage() const
// Algorithme :
// Parcourt la liste de trajets qui composent ce traje composé
// et affiche chaque trajet
{
    int nbTrajets = trajets.GetTaille();
    cout<<"Trajet compose avec "<<nbTrajets<<" trajets simples.\n";
    Node* head = trajets.GetHead();
    while(head!=nullptr){
        cout << "   ";
        head->GetTrajet()->Affichage();
        head = head->GetNext();
    }
} //----- Fin de Affichage

bool TrajetCompose::AjouterTrajet(Trajet* t)
// Algorithme :
// Il assure que la ville de départ de la nouvelle ville est la même que la
// ville d'arrivée du TrajetCompose actuel, pour que le trajet soit continu.
// Si oui, il ajoute le trajet passé en argument à la fin du trajet actuel
// et fait la mise à jour de la ville d'arrivée du trajet
// Renvoie vrai si et seulement si le trajet a été ajouté 
{
    // Si le trajet est vide, on sauvegarde la ville de depart
    if(trajets.GetHead() == nullptr){
        const char* tDepart = t->GetDepart();
        depart = new char[strlen(tDepart)+1];
        strcpy(depart, tDepart);
    }
    // Si la ville de depart de t n'est pas la même que la ville d'arrivee
    // actuelle on renovie une erreur
    else if(strcmp(arrivee, t->GetDepart())){
        cout<<"ERREUR: le depart du chemin simple actuel doit etre egal a l'arrive du anterieur\n";
        return false;
    }
    if(arrivee!=nullptr){
        delete[] arrivee;
    }

    char* tArrivee = t->GetArrivee();
    arrivee = new char[strlen(tArrivee)+1];
    strcpy(arrivee, tArrivee);

    // Ajoute le trajet à la liste de trajets du TrajetCompose
    trajets.AjouterTrajetFin(t);
    return true;
}


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose() : trajets(ListeTrajet())
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose ( )
// Algorithme :
// Parcourt toute la liste de trajets et destruit les trajets qui la composent
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

    Node* cur = trajets.GetHead();
    while(cur != nullptr){
        delete cur->GetTrajet();
        cur = cur->GetNext();
    }
} //----- Fin de ~TrajetCompose

