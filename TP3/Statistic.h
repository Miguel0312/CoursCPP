/*************************************************************************
                           Statistic  -  description
                             -------------------
    début                : 20/01/2023
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//---------- Interface de la classe <Statistic> (fichier Statistic.h) ---------
#ifndef STATISTIC_H
#define STATISTIC_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>

#include "Log.h"

using namespace std;

//------------------------------------------------------------------------
// Classe responsable par compter le nombre de fois que chaque fichier est
// consulté et afficher le 10 plus visités. Elle se charge aussi d'appliquer
// les filtres passés en ligne de commande (extension, horaire) ainsi que
// de créer le graphe des visites le cas échéant.  
//------------------------------------------------------------------------

class Statistic{
// ------------------------------------------------------------------- PUBLIC 
public:
// ------------------------------------------------------ Méthodes publiques
  void displayCount();
  // Mode d'emploi: Affiche sur la sortie standard le nom des 10 fichier les 
  // plus accedés ainsi que le nombre de fois que chacun a été lu.
  // Si la flag grapheFlag est vrai, il produit un fichier GraphWiz

//-------------------------------------------- Constructeurs - destructeur
  Statistic(vector<Log> logVectors, bool grapheF, string GrapheFi = "");
  // Mode d'emploi: Reçoit le vecteur avec les logs et la flag qui determine
  // si le graphe doit être produit. Si oui, le nom du fichier du graphe
  // doit aussi être saisi
  
  ~Statistic() {};

//-------------------------------------------------------------- PRIVATE
private:
//---------------------------------------------------------- Attributs privés
  vector<Log> logs;
  bool grapheFlag;
  string grapheFile;

//---------------------------------------------------------- Méthodes privées
  void generateGraph(string graphFileName);
  // Mode d'emploi: Crée le fichier GraphWiz correspondant aux logs dans la
  // variable privée logs et le sauvegarde sur un fichier de nom graphFileName

  static bool comp(const pair<int, string>& a, 
                              const pair<int, string>& b);
  // Mode d'emploi: Comparateur utilisé pour ordonner les fichier par nombre
  // d'accès puis, en cas d'égalité, en ordre alphabetique 
};

#endif // STATISTIC_H
