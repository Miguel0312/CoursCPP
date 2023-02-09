/*************************************************************************
  LecteurLog 
  -------------------
  début                : 20/01/2023
 *************************************************************************/
#ifndef LOG_H
#define LOG_H

//---------- Interface de la classe <LecteurLog> (fichier LecteurLog.h) ----------------
//--------------------------------------------------- Interfaces utilisées
#include <string>

using namespace std;
//------------------------------------------------------------------------
// Rôle de la classe Log
// Cette classe represente le log d'un requete au serveur.
//
//------------------------------------------------------------------------
class Log{
  //----------------------------------------------------------------- PUBLIC

  public:
    //----------------------------------------------------- Méthodes publiques
    //Getteurs
    string getIp() { return ip; }
    string getUserLogname() { return userLogname; }
    string getAuthenticatedUser() { return authenticatedUser; }
    string getDate() { return date; }
    string getMethod() { return method; }
    string getTargetURL() { return targetURL; }
    string getProtocol() { return protocol; }
    unsigned int getStatus() { return status; }
    unsigned int getSize() { return size; }
    string getReferer() { return referer; }
    string getBrowser() { return browser; }

//-------------------------------------------- Constructeurs - destructeur
    // Mode d'emploi :
    // Rempli chaque champs du Log
    Log(const string& pIp,
        const string& pUserLogname,
        const string& pAuthenticatedUser,
        const string& pDate,
        const string& pMethod,
        const string& pTargetURL,
        const string& pProtocol,
        unsigned int pStatus,
        unsigned int pSize,
        const string& pReferer,
        const string& pBrowser);

    // Mode d'emploi :
    // Parse une chaine de caracteres qui represente un log
    // pour obtenir chaque piece qui le compose
    Log(const string& logString);

  //------------------------------------------------------------------ PRIVE

  private:
  //----------------------------------------------------- Attributs prives
    string urlLocal;
    string ip;
    string userLogname;
    string authenticatedUser;
    string date;
    string method;
    string targetURL;
    string protocol;
    unsigned int status;
    unsigned int size;
    string referer;
    string browser;
};

#endif //LOG_H
