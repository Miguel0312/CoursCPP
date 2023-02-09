/*************************************************************************
  Main function 
  -------------------
  début                : 20/01/2023
 *************************************************************************/
#include<iostream>
#include <stdexcept>

#include "Statistic.h"
#include "LecteurLog.h"

using namespace std;

int main(int argc, char* argv[]){
  if(argc == 1){
    cout<<"Option invalide. Pour obtenir la liste des options possibles executez ./analog -h" << endl;
    return 1;
  }

  bool helpFlag = false;
  bool grapheFlag = false;
  string grapheFile;
  bool imageFlag = false;
  bool heureFlag = false;
  int heure;
  string fileName = "";
  int i = 1;
  //Detecte les drapeaux avec qui le programme a ete appele
  for(i = 1;i<argc;i++){
    string actuel(argv[i]);
    if(actuel == "-h"){
      helpFlag = true;
    }
    else if(actuel == "-e"){
      imageFlag = true;
    }
    else if(actuel == "-g"){
      grapheFlag = true;
      if(i +1 == argc){
        cerr<<"Usage du drapeau -g: -g nomfichier.dot";
        return 1;
      }
      i++;
      grapheFile = argv[i];
    }
    else if(actuel == "-t"){
      heureFlag = true;
      if(i+1 == argc){
        cerr<<"Usage du drapeau -t: -t heure";
        return 1;
      }
      i++;
      try{
        heure = stoi(argv[i]);
      }
      catch(std::invalid_argument& e){
        cerr<<"Formate invalide pour l'heure.\n";
        return 1;
      }
    }
    else{
      break;
    }
  }
  if(!helpFlag){
    //Si on ne demande pas de l'aide, il faut donner le fichier
    if(i >= argc){
      cerr<<"Nom du fichier log manquant.\n";
      return 1;
    }
    //Le nom du fichier est la premiere string qui ne correspond pas a un drapeaux
    fileName = argv[i];
  }

  if(helpFlag){
    cout << "Utilisation: ./analog [options] fichierDeLog" << endl;
    cout << "-h: affiche ce texte" << endl;
    cout << "-g nomfichier.dot: génére un fichier au format GraphViz"
            "du graphe analysé" << endl;
    cout << "-e: exclut tous les documents qui ont une extension d'image," 
            " css ou js" << endl;
    cout << "-t heure: ne prend en compte que les logs dans"
            " [heure, heure+1[" << endl;
    return 0;
  }


  LecteurLog lecteur(fileName, imageFlag, heureFlag, heure);
  Statistic stat(lecteur.generateLogs(), grapheFlag, grapheFile);
  stat.displayCount();
  return 0;
}
