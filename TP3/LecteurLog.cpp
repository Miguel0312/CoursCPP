/*************************************************************************
  LecteurLog 
  -------------------
  début                : 20/01/2023
 *************************************************************************/


//---------- Réalisation de la classe <LecteurLog> (fichier LecteurLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "LecteurLog.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
vector<Log> LecteurLog::generateLogs(){
  vector<Log> listeLog;
  string logSrc;
  while(getline(inFile,logSrc)){
    if(logSrc.empty())
      continue;
    Log logRes(logSrc);
    bool isImg = false;
    bool heureValide = true;
    if(imageFlag){
      string targetURL = logRes.getTargetURL();
      //jpg, png, ico, gif, svg
      string imgExtension[] = {".jpg", ".png", ".ico", ".gif", ".svg", ".css"};
      string extension = targetURL.substr(targetURL.size()-4);
      for(string ext : imgExtension){
        if(extension == ext){
          isImg = true;
          break;
        }
      }

      if(!isImg && targetURL.substr(targetURL.size() - 3) == ".js")
        isImg = true;
    }

    if(heureFlag){
      string dateLog = logRes.getDate();
      size_t startHeure = dateLog.find(":") + 1;
      int heureLog = stoi(dateLog.substr(startHeure, 2));
      if(heureLog != heure){
        heureValide = false;
      }
    }
    if(!isImg && heureValide){
      listeLog.push_back(logRes);
    }
  }


  //Retourne le descripteur au debut du fichier
  inFile.seekg(0);
  return listeLog;
} //----- Fin de generateLogs

//-------------------------------------------- Constructeurs - destructeur
LecteurLog::LecteurLog(const string& filePath, bool imageF, bool heureF, int heureD):
  imageFlag(imageF), heureFlag(heureF), heure(heureD){
    inFile.open(filePath);
} //----- Fin du constructeur


