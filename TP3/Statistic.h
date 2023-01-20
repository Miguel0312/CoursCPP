#ifndef STATISTIC_H
#define STATISTIC_H

#include <string>
#include <map>
#include <vector>

#include "Log.h";

using namespace std;

class Statistic{
public:
// TODO: pass the arguments relative to the command line options
  Statistic(string logFileName);
  ~Statistic() {};

  void generateGraph(string graphFileName);

private:
  vector<Log> logs;
};

#endif