/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 25/11/2022
    auteurs              : Miguel Pereira, Artur Pereira
*************************************************************************/

//------ Réalisation de la classe <Statistic> (fichier Statistic.cpp) --------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include<utility>
#include<algorithm>

using namespace std;

// -------------------------------------------------------- Include personnel
#include "Statistic.h"
#include "Log.h"

// ----------------------------------------------------------------- PUBLIC

// ------------------------------------------------------ Méthodes publiques

void Statistic::displayCount(){
  // Compte le nombre fois que chaque domaine est accedé
  map<string, int> count;
  for(int i = 0; i<(int)logs.size();i++){
    string targetURL = logs[i].getTargetURL();
    auto targetLocation = count.find(targetURL);
    if(targetLocation != count.end()){
      targetLocation->second++;
    }
    else{
      count[targetURL] = 1;
    }
  }

  // Si le graphe doit être crée, on appele la méthode generateGraphe
  if(grapheFlag){
    cout << "Dot-file " << grapheFile << " generated" << endl;
    generateGraph(grapheFile);
  }

  // Création d'un std::set qui va ordonner les domaines selon comp
  // comp est tel que les fichiers le plus accedés aparaîssent avant et, dans le
  // cas où il y a une égalité, ils sont organisés en ordre alphabétique
  set<pair<int,string>, decltype(&comp)> order(&comp);
  for(auto it = count.begin(); it!=count.end(); it++){
    order.insert(make_pair(it->second,it->first));
  }

  // Affichage des 10 premiers pages du std::set
  int maxLines = 10, lines = 0;
  auto it = order.begin();
  while(lines < maxLines && it != order.end()){
    int cur = it->first;
    while(it != order.end() && it->first == cur){
      cout << it->second << " (" << it->first << " hits)" << endl;
      lines++;
      it++;
    }
  }
} // ---------- Fin de displayCount

// ------------------------------------------------------ Méthodes privées

void Statistic::generateGraph(string graphFileName){
  // Associe chaque fichier à un id
  map<string, int> nodes;
  // Graphe de la forme directed weighted edge list
  map<pair<int, int>, int> edges;

  unsigned int id = 0;

  for(Log log : logs){
    map<string, int>::iterator posRef = nodes.find(log.getReferer());
    unsigned int idRef, idTarget;
    // Si le referer n'a pas d'id, on lui donne un, sinon on le récupere 
    if(posRef != nodes.end())
      idRef = posRef->second;
    else{
      nodes[log.getReferer()] = ++id;
      idRef = id;
    }

    // Si le fichier n'a pas d'id, on lui donne un, sinon on le récupere
    map<string, int>::iterator posTarget = nodes.find(log.getTargetURL());
    if(posTarget != nodes.end())
      idTarget = posTarget->second;
    else{
      nodes[log.getTargetURL()] = ++id;
      idTarget = id;
    }

    // Augmente le poids de la arête du referer vers le fichier
    edges[{idRef, idTarget}]++;
  }

  // Formatte les données du graphe pour que GrapheWiz puisse le lire
  ofstream gos;
  gos.open(graphFileName);
  gos << "digraph {\n";

  for(pair<string, int> node : nodes){
    gos << "node" << node.second << " [label=\"" 
      << node.first << "\"];\n";
  }

  for(pair<pair<int, int>, int> edge : edges){
    gos << "node" << edge.first.first << " -> " << "node"
      << edge.first.second << " [label=\"" << edge.second << "\"];\n";
  }
  gos << "}" << endl;
} // --------- Fin de generateGraph

bool Statistic::comp(const pair<int, string>& a, const pair<int, string>& b){
  if(a.first != b.first)
    return a.first > b.first;
  return a.second < b.second;
} // ----------- Fin de comp

//-------------------------------------------- Constructeurs - destructeur

Statistic::Statistic(vector<Log> logVector, bool grapheF, string grapheFi):
           logs(logVector), 
           grapheFlag(grapheF), 
           grapheFile(grapheFi){} //-------- Fin de Statistic