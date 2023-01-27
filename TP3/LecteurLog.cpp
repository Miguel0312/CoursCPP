#include<fstream>
#include<string>
#include<vector>
#include<iostream>

#include "LecteurLog.h"

using namespace std;

LecteurLog::LecteurLog(const string& filePath, bool imageF, bool heureF, int heureD):
  imageFlag(imageF), heureFlag(heureF), heure(heureD){
    inFile.open(filePath);
  }

vector<Log> LecteurLog::generateLogs(){
  vector<Log> listeLog;
  string logSrc;
  while(getline(inFile,logSrc)){
    Log logRes(logSrc);
    bool isImg = false;
    bool heureValide = true;
    if(imageFlag){
      string targetURL = logRes.getTargetURL();
      //jpg, png, ico, gif, svg
      string imgExtension[] = {".jpg", ".png", ".ico", ".gif", ".svg"};
      string extension = targetURL.substr(targetURL.size()-5);
      for(string ext : imgExtension){
        if(extension == ext){
          isImg = true;
          break;
        }
      }
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

  inFile.seekg(0);
  return listeLog;
}
