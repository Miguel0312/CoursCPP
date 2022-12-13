#include<iostream>
using namespace std;

#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

#define BUF_SIZE 100

void afficherMenu(){
    cout<<"Options:\n";
    cout<<"1) Ajouter un chemin simple.\n";
    cout<<"2) Ajouter un chemin compose.\n";
    cout<<"3) Recherche simple.\n";
    cout<<"4) Recherche avancee.\n";
    cout<<"5) Quitter.\n";
}

void ajouterCheminSimple(Catalogue &c){
    char depart[BUF_SIZE], arrivee[BUF_SIZE], transport[BUF_SIZE];
    cout<<"Ville de depart: ";
    cin>>depart;
    cout<<"Ville d'arrivee: ";
    cin>>arrivee;
    cout<<"Moyen de transport: ";
    cin>>transport;
    TrajetSimple* cur = new TrajetSimple(depart, arrivee, transport);
    c.AjouterTrajet(cur);
    
}

void ajouterCheminCompose(Catalogue &c){
    cout<<"Quelle est la taille du chemin?\n";
    int taille;
    cin>>taille;
    char depart[BUF_SIZE], arrivee[BUF_SIZE], transport[BUF_SIZE];
    TrajetCompose* newTrajet = new TrajetCompose();

    for(int i =  0;i<taille;i++){
        cout<<"Informations pour le trajet "<<i+1<<"\n";
        cout<<"Ville de depart: ";
        cin>>depart;
        cout<<"Ville d'arrivee: ";
        cin>>arrivee;
        cout<<"Moyen de transport: ";
        cin>>transport;
        TrajetSimple* cur = new TrajetSimple(depart, arrivee, transport);
        newTrajet->AjouterTrajet(*cur);
        delete cur;
    }
    c.AjouterTrajet(newTrajet);
}

void rechercheSimple(const Catalogue &c){
    char depart[BUF_SIZE], arrivee[BUF_SIZE];
    cout<<"Ville de depart: ";
    cin>>depart;
    cout<<"Ville d'arrivee: ";
    cin>>arrivee;
    c.RechercheSimple(depart, arrivee);
}

void rechercheAvancee(const Catalogue &c){
    char depart[BUF_SIZE], arrivee[BUF_SIZE];
    cout<<"Ville de depart: ";
    cin>>depart;
    cout<<"Ville d'arrivee: ";
    cin>>arrivee;
    c.RechercheAvancee(depart, arrivee);
}

int main(){
    bool continuer = true;
    Catalogue c;
    ListeTrajet liste;

    while(continuer){
        int option;
        afficherMenu();
        cin>>option;
        switch(option){
        case 1:
            ajouterCheminSimple(c);
            break;
        case 2:
            ajouterCheminCompose(c);
            break;
        case 3:
            rechercheSimple(c);
            break;
        case 4:
            rechercheAvancee(c);
            break;
        case 5:
            continuer = false;
            break;
        }

    }
}