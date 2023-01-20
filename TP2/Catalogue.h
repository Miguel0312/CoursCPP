/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------
#if !defined (CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajet.h"
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------------------
// Classe qui implémente un catalogue contenant une liste de trajets et qui
// permmet la recherche des chemins entre deux villes en parcourant ces
// trajets
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  void AjouterTrajet(const Trajet* t);
  // Mode d'emploi :
  // Ajoute un trajet à la liste de trajets du catalogue

  bool RechercheSimple(const char* depart, const char* arrivee) const;
  // Mode d'emploi :
  // Affiche les chemins composés d'un seul trajet entre les villes de départ
  // et d'arrivée
  // Renvoie vrai si et seulement si au moins un chemin entre les villes a
  // été trouvé

  bool RechercheAvancee(const char* depart, const char* arrivee) const;
  // Mode d'emploi :
  // Affiche tous les chemins entre les villes de départ et d'arrivée, même
  // ceux qui sont composés de plus d'un trajet
  // Renvoie vrai si et seulement si au moins un chemin entre les villes a
  // été trouvé

  void Affichage() const;
  // Mode d'emploi :
  // Affiche tous les trajets du catalogue dans l'ordre opposée à l'ordre
  // d'insertion

  void SauvegarderTous(const string& file) const;
  // Mode d'emploi:
  // Sauvegarde tous les trajets du catalogue dans le fichier 'file'

  void SauvegarderType(const string& file, char type) const;
  // Mode d'emploi:
  // Sauvegarde tous les trajets du catalogue qui ont le meme type que 'type'
  // dans le fichier 'file'. 'S' est pour trajet simple et 'C' pour compose.

  void SauvegarderVille(const string& file, string depart, string arrivee) const;
  // Mode d'emploi:
  // Sauvegarde tous les trajets du catalogue qui ont la meme ville de depart et d'arrivee que
  // 'depart' et 'arrive' dans le fichier file.
  // Si 'depart' est la chaine vide, la fonction verifie seulement si la ville d'arrivee
  // corresponde avec le parametre 'arrrivee'.
  // Si 'arrivee' est la chaine vide, la fonction verifie seulement si la ville de depart
  // corresponde avec le parametre 'depart'.

  void SauvegarderIntervalle(const string& file, int debut, int fin) const;
  // Mode d'emploi:
  // Sauvegarde tous les trajets du catalogue dans l'intervalle [debut, fin]
  // dans le fichier file. L'ordre est 1-indexed.

  void ChargerTous(const string& file);
  // Mode d'emploi:
  // Charge tous les trajets du fichier 'file' dans le catalogue.

  void ChargerType(const string& file, char type);
  // Mode d'emploi:
  // Charge tous les trajets du fichier 'file'  meme type que 'type'
  // dans le catalogue. 'S' est pour trajet simple et 'C' pour compose.

  void ChargerVille(const string& file, string depart, string arrivee);
  // Mode d'emploi:
  // Charge tous les trajets du fichier 'file' qui ont la meme ville de depart et d'arrivee que
  // 'depart' et 'arrive' dans le catalogue.
  // Si 'depart' est la chaine vide, la fonction verifie seulement si la ville d'arrivee
  // corresponde avec le parametre 'arrrivee'.
  // Si 'arrivee' est la chaine vide, la fonction verifie seulement si la ville de depart
  // corresponde avec le parametre 'depart'.

  void ChargerIntervalle(const string& file, int debut, int fin);
  // Mode d'emploi:
  // Charge tous les trajets du fichier 'file' dans l'intervalle [debut, fin]
  // dans le catalogue. L'ordre est 1-indexed.

//-------------------------------------------- Constructeurs - destructeur
  Catalogue();
  // Mode d'emploi (constructeur de copie) :
  // Construit un nouveau catalogue vide

  virtual ~Catalogue();
  // Mode d'emploi :
  //Détruit le trajet composé ainsi que les trajets qui le composent

//------------------------------------------------------------------ PRIVE
private:
//----------------------------------------------------- Méthodes privées
  bool dfs(const char* const depart,
           const char* const arrivee, 
           bool* visited,
           ListeTrajet& cheminActuel, 
           int n, 
           int& m) const;
  // Mode d'emploi :
  // Fonction auxiliaire pour la méthode RechercheAvancée
  // Utilise une méthode récursive pour faire un depth first search entre les
  // villes de départ et d'arrivée

  void Chargement(ifstream& origine, const string& description);

  TrajetSimple* ChargerTrajetSimple(const string& description) const;

//----------------------------------------------------- Attributs protégés
  ListeTrajet trajets;
};

#endif // CATALOGUE_H
