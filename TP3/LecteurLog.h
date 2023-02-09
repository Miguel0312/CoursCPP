/*************************************************************************
  LecteurLog 
  -------------------
  début                : 20/01/2023
 *************************************************************************/

//---------- Interface de la classe <LecteurLog> (fichier LecteurLog.h) ----------------
#ifndef LECTEUR_LOG_H

#define LECTEUR_LOG_H 

//--------------------------------------------------- Interfaces utilisées
#include<fstream>
#include<string>
#include<vector>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
#include "Log.h"
//------------------------------------------------------------------------
// Rôle de la classe lecteurLog
//
// Cette classe est utilise pour lire un fichier avec un log apache et produire
// une liste de logs.
// Il est possible de specifier un interval de temps pour chercher les logs
// et choisir ignorer les fichiers de type image,css et javascript
//
//------------------------------------------------------------------------

class LecteurLog
{
  //----------------------------------------------------------------- PUBLIC

  public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi : genere une liste avec les differents logs dans le fichier
    // Juste les logs qui respectent la condition d'heure et ont les extensions
    // correctes sont ajoutes a la liste
    // Contrat : Apres la lecture, le descripteur de fichier pointe vers le premier
    // caractere du fichier. Donc, c'est possible d'utiliser le meme LecteurLog
    // pour creer la liste a nouveau
    //
    vector<Log> generateLogs();


    //-------------------------------------------- Constructeurs - destructeur

    // Mode d'emploi :
    // Ouvre le fichier indique par filePath. Si imageF est vrai, la generation de logs
    // va ignorer les fichiers de type image, css et javascript.
    // Si heureF est vrai, just les logs qui ont ete generes dans [heureD,heureD+1[ sont
    // consideres.
    LecteurLog(const string& filePath, bool imageF = false, bool heureF = false, int heureD = 0);

    //------------------------------------------------------------------ PRIVE

  private:
    //----------------------------------------------------- Attributs privees
    ifstream inFile;
    bool imageFlag;
    bool heureFlag;
    int heure;

};


#endif // LECTEUR_LOG_H


