    #include<fstream>
    #include<string>
    #include<vector>

    #include "LecteurLog.h"

    using namespace std;
    
    LecteurLog::LecteurLog(const string& filePath){
        inFile.open(filePath);
    }

    vector<Log> LecteurLog::generateLogs(){
        vector<Log> listeLog;
        string logSrc;
        while(getline(inFile,logSrc)){
            listeLog.emplace_back(logSrc);
        }

        inFile.seekg(0);
        return listeLog;
    }