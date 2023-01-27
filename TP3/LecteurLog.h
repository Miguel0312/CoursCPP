#include<fstream>
#include<string>
#include<vector>

#include "Log.h"
using namespace std;

class LecteurLog{
    public:
    LecteurLog(const string& filePath);

    vector<Log> generateLogs();
    private:
    ifstream inFile;
};