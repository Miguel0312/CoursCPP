#include "Log.h"

#include <string>

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
      browser(pBrowser) {}