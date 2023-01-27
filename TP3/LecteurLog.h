#include<fstream>
#include<string>
#include<vector>

#include "Log.h"
using namespace std;

class LecteurLog{
    public:
    LecteurLog(const string& filePath, bool imageF = false, bool heureF = false, int heureD = 0);

    vector<Log> generateLogs();
    private:
      ifstream inFile;
      bool imageFlag;
      bool heureFlag;
      int heure;
};
