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
  cout<<"5) Charger trajets.\n";
  cout<<"6) Sauvegarder trajets.\n";
  cout<<"7) Quitter.\n";
}

void afficherMenuSauvegarde(){
  cout<<"Options:\n";
  cout<<"1) Sauvegarder tout.\n";
  cout<<"2) Sauvegarder selon type de trajet.\n";
  cout<<"3) Sauvegarder selon ville de depart.\n";
  cout<<"4) Sauvegarder selle ville d'arrivee.\n";
  cout<<"5) Sauvegarder selon depart et arrivee.\n";
  cout<<"6) Sauvegarder intervalle.\n";
}

void afficherMenuCharge(){
  cout<<"Options:\n";
  cout<<"1) Charger tout.\n";
  cout<<"2) Charger selon type de trajet.\n";
  cout<<"3) Charger selon ville de depart.\n";
  cout<<"4) Charger selle ville d'arrivee.\n";
  cout<<"5) Charger selon depart et arrivee.\n";
  cout<<"6) Charger intervalle.\n";
}

void ajouterCheminSimple(Catalogue &c){
  cin.ignore(1,'\n');
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
  cin.ignore(1,'\n');
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
  cin.ignore(1,'\n');
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
  cin.ignore(1,'\n');
  string depart, arrivee;
  cout<<"Ville de depart: ";
  getline(cin, depart);
  cout<<"Ville d'arrivee: ";
  getline(cin, arrivee);
  if(!c.RechercheAvancee(depart.c_str(), arrivee.c_str())){
    cout<<"Il n'y a aucun chemin possible entre "<< depart << " et " << arrivee << endl;
  }
}

void ChargerTout(Catalogue& c, string destination){
  c.ChargerTous(destination);
}

void ChargerType(Catalogue& c, string destination){
  string type;
  cout<<"1) Chemins simples\n";
  cout<<"2) Chemins composes\n";
  int option;
  cin>>option;
  if(option == 1){
    c.ChargerType(destination, 'S');
  }
  else if(option == 2){
    c.ChargerType(destination, 'C');
  }
  else{
    cout<<"Option invalide";
  }
}

void ChargerVilleDepart(Catalogue& c, string destination){
  cin.ignore(1,'\n');
  cout<<"Entrez la ville de depart: ";
  string depart;
  cin>>depart;
  c.ChargerVille(destination, depart, "");
}

void ChargerVilleArrivee(Catalogue& c, string destination){
  cin.ignore(1,'\n');
  cout<<"Entrez la ville d'arrivee: ";
  string arrivee;
  cin>>arrivee;
  c.ChargerVille(destination, "", arrivee);
}

void ChargerVilleDepartArrivee(Catalogue& c, string destination){
  cin.ignore(1,'\n');
  string depart, arrivee;
  cout<<"Entrez la ville de depart: ";
  cin>>depart;
  cout<<"Entrez la ville d'arrivee: ";
  cin>>arrivee;
  c.ChargerVille(destination, depart, arrivee);
}

void ChargerIntervalle(Catalogue& c, string destination){
  int debut, fin;
  cout<<"Entrez le nombre du premier trajet: ";
  cin>>debut;
  cout<<"Entrez le nombre du dernier trajet: ";
  cin>>fin;
  c.ChargerIntervalle(destination, debut, fin);
}

void chargerTrajets(Catalogue& c){
  cout<<"Entrez le nom du fichier: ";
  string destination;
  cin>>destination;
  afficherMenuCharge();
  int option;
  if(scanf("%d", &option) != 1){
    cout<<"Entrez un nombre.\n";
  }
  switch(option){
    case 1:
      ChargerTout(c, destination);
      break;
    case 2:
      ChargerType(c, destination);
      break;
    case 3:
      ChargerVilleDepart(c, destination);
      break;
    case 4:
      ChargerVilleArrivee(c, destination);
      break;
    case 5:
      ChargerVilleDepartArrivee(c, destination);
    case 6:
      ChargerIntervalle(c, destination);
      break;
    default:
      cout<<"Option non valide.\n";
  }
}

void sauvegarderTout(const Catalogue& c, string destination){
  c.SauvegarderTous(destination);
}

void sauvegarderType(const Catalogue& c, string destination){
  string type;
  cout<<"1) Chemins simples\n";
  cout<<"2) Chemins composes\n";
  int option;
  cin>>option;
  if(option == 1){
    c.SauvegarderType(destination, 'S');
  }
  else if(option == 2){
    c.SauvegarderType(destination, 'C');
  }
  else{
    cout<<"Option invalide";
  }
}

void sauvegarderVilleDepart(const Catalogue& c, string destination){
  cin.ignore(1,'\n');
  cout<<"Entrez la ville de depart: ";
  string depart;
  getline(cin, depart);
  c.SauvegarderVille(destination, depart, "");
}

void sauvegarderVilleArrivee(const Catalogue& c, string destination){
  cin.ignore(1,'\n');
  cout<<"Entrez la ville d'arrivee: ";
  string arrivee;
  getline(cin, arrivee);
  c.SauvegarderVille(destination, "", arrivee);
}

void sauvegarderVilleDepartArrivee(const Catalogue& c, string destination){
  cin.ignore(1,'\n');
  string depart, arrivee;
  cout<<"Entrez la ville de depart: ";
  getline(cin, depart);
  cout<<"Entrez la ville d'arrivee: ";
  getline(cin, arrivee);
  c.SauvegarderVille(destination, depart, arrivee);
}

void sauvegarderIntervalle(const Catalogue& c, string destination){
  int debut, fin;
  cout<<"Entrez le nombre du premier trajet: ";
  cin>>debut;
  cout<<"Entrez le nombre du dernier trajet: ";
  cin>>fin;
  c.SauvegarderIntervalle(destination, debut, fin);
}

void sauvegarderTrajets(const Catalogue& c){
  cout<<"Entrez le nom du fichier: ";
  string destination;
  cin>>destination;
  afficherMenuSauvegarde();
  int option;
  if(scanf("%d", &option) != 1){
    cout<<"Entrez un nombre.\n";
  }
  switch(option){
    case 1:
      sauvegarderTout(c, destination);
      break;
    case 2:
      sauvegarderType(c, destination);
      break;
    case 3:
      sauvegarderVilleDepart(c, destination);
      break;
    case 4:
      sauvegarderVilleArrivee(c, destination);
      break;
    case 5:
      sauvegarderVilleDepartArrivee(c, destination);
      break;
    case 6:
      sauvegarderIntervalle(c, destination);
      break;
    default:
      cout<<"Option non valide.\n";
  }
}

int main(){
  bool continuer = true;
  Catalogue c;
  ListeTrajet liste;

  while(continuer){
    int option;
    afficherMenu();
    if(scanf("%d", &option) != 1){
      cout<<"Entrez un nombre.\n";
    }
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
        chargerTrajets(c);
        break;
      case 6:
        sauvegarderTrajets(c);
        break;
      case 7:
        continuer = false;
        break;
      default:
        cout<<"Nombre non valide.\n";
    }
  }
}
