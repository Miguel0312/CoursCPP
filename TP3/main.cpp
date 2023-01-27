#include<iostream>

#include "Statistic.h"
#include "LecteurLog.h"

using namespace std;

int main(int argc, char* argv[]){
  if(argc == 1){
    cout<<"Option invalide. Pour obtenir la liste des options possibles executez ./analog -h" << endl;
    return 1;
  }
  LecteurLog lecteur(argv[1]);
  Statistic stat(lecteur.generateLogs());
  stat.displayCount();
  return 0;
}
