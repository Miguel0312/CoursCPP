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
  if(i>=argc){
    cerr<<"Nom du fichier log manquant.\n";
    return 1;
  }
  fileName = argv[i];


  LecteurLog lecteur(argv[1], imageFlag);
  Statistic stat(lecteur.generateLogs(), grapheFlag, grapheFile);
  stat.displayCount();
  return 0;
}
