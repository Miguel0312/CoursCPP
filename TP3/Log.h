#ifndef LOG_H
#define LOG_H

#include <string>

using namespace std;

class Log{
public:
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

  Log(const string& logString);
  
  virtual ~Log() {};

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

private:
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

#endif
