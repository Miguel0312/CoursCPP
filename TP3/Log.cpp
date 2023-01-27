#include "Log.h"

#include <string>
#include <regex>
#include<fstream>
#include <iostream>
#include<exception>

using namespace std;

Log::Log(const string& pIp,
    const string& pUserLogname,
    const string& pAuthenticatedUser,
    const string& pDate,
    const string& pMethod,
    const string& pTargetURL,
    const string& pProtocol,
    unsigned int pStatus,
    unsigned int pSize,
    const string& pReferer,
    const string& pBrowser) :
  ip(pIp),
  userLogname(pUserLogname),
  authenticatedUser(pAuthenticatedUser),
  date(pDate),
  method(pMethod),
  targetURL(pTargetURL),
  protocol(pProtocol),
  status(pStatus),
  size(pSize),
  referer(pReferer),
  browser(pBrowser) {
    ifstream urlLocalFile;
    urlLocalFile.open("urlLocal.txt");
    getline(urlLocalFile, urlLocal);
  }

  Log::Log(const string& logString){

    ifstream urlLocalFile;
    urlLocalFile.open("urlLocal.txt");
    getline(urlLocalFile, urlLocal);

    string ipEx = "([0-9\\.]*)";
    string userLognameEx = "(-)";
    string authenticatedUserEx = "(-)";
    string dateEx = "([a-zA-Z0-9\\/:]* [0-9\\+\\-]*)";
    string methodEx = "([A-Za-z]*)";
    string targetURLEx = "([^ ]*)";
    string protocolEx = "([^ ]*)";
    string statusEx = "([0-9]*)";
    string sizeEx = "([0-9]*|-)";
    string refererEx = "([^ ]*)";
    string browserEx = "([^\"]*)";


    regex logEx(ipEx + " " + userLognameEx + " " + authenticatedUserEx + " \\[" + dateEx + "\\] \"" + methodEx + " " + targetURLEx + " " + protocolEx + "\" " + statusEx + " " + sizeEx+ " \"" + refererEx + "\" \"" + browserEx + "\"");

    std::smatch sm;
    regex_search(logString, sm, logEx);

    ip = sm[1];
    userLogname = sm[2];
    authenticatedUser = sm[3];
    date = sm[4];
    method = sm[5];
    targetURL = sm[6];
    protocol = sm[7];
    status = stoul(sm[8]);
    try{
      size = stoul(sm[9]);
    } catch(invalid_argument e){
      size = 0;
    }
    referer = sm[10];
    //Formate le urlLocal pour dans la forme d'une regex
    // Il faut escaper tous les '.' et '/'
    string formatedLocal = urlLocal;
    int indice = 0;
    string escapeStr = "\\";
    while(indice<=formatedLocal.size()){
      if(formatedLocal[indice] == '/' || formatedLocal[indice] == '.'){
        formatedLocal.replace(indice,1,escapeStr + formatedLocal[indice]);
        indice++;
      }
      indice++;
    }
    regex localEx(formatedLocal + "(.*)");
    smatch refererMatch;
    regex_search(referer, refererMatch, localEx);
    if(!refererMatch.empty()){
      referer = "/";
      referer += refererMatch[1];
    }

    browser = sm[11];

  }
