/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Node.h"
#include "ListeTrajet.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AjouterTrajet(const Trajet* t)
{
    trajets.AjouterTrajetFin(t);
} //----- Fin de AjouterTrajet

bool Catalogue::RechercheSimple(const char* depart, const char* arrivee) const
// Algorithme :
// Parcourt toute la liste de trajets. Pour chaque trajet dont la ville de
// départ et la ville d'arrivée sont les villes recherchés affiche le trajet.
// Si au moin un chemin entre les deux villes a été trouvé, renvoie vrai,
// sinon renvoie faux. 
{
    // La liste où les trajets valides seront mis
    ListeTrajet chemins;
    // Pointeur utilisé pour parcourir la liste de trajets
    Node* cur = trajets.GetHead();

    while(cur != nullptr){
        // Si le trajet actuel a la ville de départ et la ville d'arrivée
        // recherchées, on l'ajoute à la liste de réponses
        if(strcmp(depart, cur->GetTrajet()->GetDepart()) == 0 &&
           strcmp(arrivee, cur->GetTrajet()->GetArrivee()) == 0){
            chemins.AjouterTrajet(cur->GetTrajet());
           }
        cur = cur->GetNext();
    }

    if(chemins.GetTaille() > 0){
        cout << "Chemins possibles entre " 
             << depart 
             << " et " 
             << arrivee 
             << endl;
    }
    // Retourne faux si aucun chemin n'a pas été trouvé
    else{
        return false;
    }

    // Pointeur utilisé pour parcourir la liste de réponses
    cur = chemins.GetHead();
    int n = 1;
    while(cur != nullptr){
        cout << n++ << ") ";
        cur->GetTrajet()->Affichage();
        cur = cur->GetNext();
        if(cur != nullptr)
            printf("\r\n");
    }
    return true;
} //----- Fin de RechercheSimple

bool Catalogue::RechercheAvancee(const char* depart, const char* arrivee) const
// Algorithme:
// Utilise une DFS (depth first search) pour trouver tous les chemins entre
// les villes de départ et arrivee, même ceux qui sont composés par plus d'un
// trajet.
{
    cout << "Chemins possibles entre "
         << depart 
         << " et " 
         << arrivee
         << " (recherche avancee)"
         << endl;
    
    if(trajets.GetTaille() == 0)
        return false;
    // Obtenir les noeuds
    int n = trajets.GetTaille(), m = 1;
    
    // Le tableau indique si le i ème trajet a déjà été visité dans ce chemin,
    // ce qui permmet le traitement des boucles dans la liste de trajets
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;

    // Liste qu'enregistre les noeuds visités par le chemin actuel
    ListeTrajet cheminActuel;
    // resultat est vrai si et seulement si au moins au chemin a été trouvé
    // entre les villes de départ et arrivee
    bool resultat = dfs(depart, arrivee, visited, cheminActuel, n, m);

    delete[] visited;

    return resultat;
} //----- Fin de RechercheAvancee

void Catalogue::Affichage() const{
    Node* cur = trajets.GetHead();
    // Affiche chaque trajet du catalogue
    while(cur != nullptr){
        cur->GetTrajet()->Affichage();
        cur = cur->GetNext();
    }
} //----- Fin de Affichage

void Catalogue::Sauvegarder(ofstream& destin) const{
    Node* actuel = trajets.GetHead();
    while(actuel != nullptr){
        actuel->GetTrajet()->Sauvegarder(destin);
        actuel = actuel->GetNext();
    }
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue() :
trajets(ListeTrajet())
// Algorithme :
// Fait l'affectation d'une nouvelle ListeTrajet vide à l'attribut trajets
{
#ifdef MAP
    cout << "Appel au constructeur de copie de Catalogue" << endl;
#endif
} //----- Fin du constructeur standard de Catalogue

Catalogue::~Catalogue()
// Algorithme :
// Parcourt toute la liste de trajets et destruit les trajets qui la composent
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

    Node* cur = trajets.GetHead();
    while(cur != nullptr){
        delete cur->GetTrajet();
        cur = cur->GetNext();
    }
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool Catalogue::dfs(const char* const depart,
                    const char* const arrivee, 
                    bool* visited,
                    ListeTrajet& cheminActuel, 
                    int n, 
                    int& m) const
// Algorithme :
// Si les villes de départ et d'arrivee sont les mêmes, donc un chemin entre les
// villes a été trouvé et il l'affiche
// Sinon, ajoute la ville actuelle au chemin et appele dfs de manière recursive
// pour chaque ville accessible à partir de la ville actuel
// Renvoie vrai si et seulement si au moins un chemin entre les deux villes
// a été trouvé
{
    // Si les villes de départ et d'arrivee sont les mêmes, donc un chemin entre les
    // villes a été trouvé et il l'affiche
    // Renvoie vrai
    if(strcmp(depart, arrivee) == 0){
        cout << m << ")" << endl;
        cheminActuel.Affichage();
        m++;
        return true;
    }

    // Pointeur utilisé pour parcourir la liste de trajets
    Node* curNode = trajets.GetHead();
    // Variable qui enregistre si un chemin a été trouvé
    bool resultat = false;
    for(int j = 0; j < n; j++){
        // La condition !visited[j] évite qu'on entre dans une boucle infinie
        if(!visited[j] && strcmp(depart, curNode->GetTrajet()->GetDepart()) == 0){
            visited[j] = true;
            // Ajoute le trajet au cheminActuel
            cheminActuel.AjouterTrajetFin(curNode->GetTrajet());
            // Appele dfs de manière recursive pour chercher un chemin entre
            // le nouveau point de départ et la ville d'arrivée
            resultat = dfs(curNode->GetTrajet()->GetArrivee(),
                           arrivee, 
                           visited, 
                           cheminActuel, 
                           n, 
                           m) || resultat;
            //Retourne à la ville de départ actuelle
            cheminActuel.EnleverFin();
            visited[j] = false;
        }
        curNode = curNode->GetNext();
    }

    return resultat;
} //----- Fin de dfs

void Catalogue::Chargement(ifstream& origine, const string& description){
    if(description[0] == 'S'){
        Trajet* nTrajet = ChargerTrajetSimple(description);
        AjouterTrajet(nTrajet);
    } else if(description[0] == 'C'){
        int index = description.rfind(':');
        int nbTrajets = stoi(description.substr(index+1));
        TrajetCompose* nTrajet = new TrajetCompose();
        string ligne;
        for(int i = 0; i < nbTrajets; i++){
            getline(origine, ligne);
            Trajet* sousTrajet = ChargerTrajetSimple(ligne);
            nTrajet->AjouterTrajet(sousTrajet);
        }

        AjouterTrajet(nTrajet);
    }
}

TrajetSimple* Catalogue::ChargerTrajetSimple(const string& description){
    // Sauvegarde les villes de depart, arrivee et le moyen de transport
    // Dans cet ordre
    string info[3];
    int index = 1, fin = description.find(':', index+1);
    for(int i = 0; i < 3; i++){
        info[i] = description.substr(index+1, fin-index-1);
        index = fin;
        fin = description.find(':', index+1);
    }
    Trajet* nTrajet = new TrajetSimple(info[0].c_str(),
                                       info[1].c_str(), 
                                       info[2].c_str());
}