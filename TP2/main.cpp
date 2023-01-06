#include<iostream>
#include<fstream>
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
    string depart, arrivee, transport;
    cout<<"Ville de depart: ";
    getline(cin, depart);
    cout<<"Ville d'arrivee: ";
    getline(cin, arrivee);
    cout<<"Moyen de transport: ";
    getline(cin, transport);
    TrajetSimple* cur = new TrajetSimple(depart.c_str(), arrivee.c_str(), transport.c_str());
    c.AjouterTrajet(cur);
}

void ajouterCheminCompose(Catalogue &c){
    string depart, arrivee, transport;
    cout<<"Quelle est la taille du chemin?\n";
    int taille;
    cin>>taille;
    TrajetCompose* newTrajet = new TrajetCompose();

    for(int i =  0;i<taille;i++){
        cout<<"Informations pour le trajet "<<i+1<<"\n";
        cout<<"Ville de depart: ";
        getline(cin, depart);
        cout<<"Ville d'arrivee: ";
        getline(cin, arrivee);
        cout<<"Moyen de transport: ";
        getline(cin, transport);
        TrajetSimple* cur = new TrajetSimple(depart.c_str(), arrivee.c_str(), transport.c_str());
        if(!newTrajet->AjouterTrajet(cur)){
          i--;
          delete cur;
        }
    }
    c.AjouterTrajet(newTrajet);
}

void rechercheSimple(const Catalogue &c){
    string depart, arrivee;
    cout<<"Ville de depart: ";
    getline(cin, depart);
    cout<<"Ville d'arrivee: ";
    getline(cin, arrivee);
    if(!c.RechercheSimple(depart.c_str(), arrivee.c_str())){
      cout<<"Il n'y a aucun chemin direct possible entre "<< depart << " et " << arrivee << endl;
    }
}

void rechercheAvancee(const Catalogue &c){
    string depart, arrivee;
    cout<<"Ville de depart: ";
    getline(cin, depart);
    cout<<"Ville d'arrivee: ";
    getline(cin, arrivee);
    if(!c.RechercheAvancee(depart.c_str(), arrivee.c_str())){
      cout<<"Il n'y a aucun chemin possible entre "<< depart << " et " << arrivee << endl;
    }
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