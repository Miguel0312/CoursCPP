#include <string>
#include <map>
#include <vector>
#include <fstream>

#include "Statistic.h"
#include "Log.h"

using namespace std;

Statistic::Statistic(string logFileName){
  // TODO: parse file and generate logs
  map<string, int> count;
}

void Statistic::generateGraph(string graphFileName){
  map<string, int> nodes;
  map<pair<int, int>, int> edges;

  unsigned int id = 0;

  for(Log log : logs){
    map<string, int>::iterator posRef = nodes.find(log.getReferer());
    unsigned int idRef, idTarget; 
    if(posRef != nodes.end())
      idRef = posRef->second;
    else{
      nodes[log.getReferer()] = ++id;
    }

    map<string, int>::iterator posTarget = nodes.find(log.getTargetURL());
    if(posTarget != nodes.end())
      idTarget = posTarget->second;
    else{
      nodes[log.getTargetURL()] = ++id;
    }

    edges[{idRef, idTarget}]++;
  }

  ofstream gos;
  gos.open(graphFileName);
  gos << "digraph {\n";

  for(pair<string, int> node : nodes){
    gos << "node" << node.second << " [label=\"" 
        << node.first << "\"];\n";
  }

  for(pair<pair<int, int>, int> edge : edges){
    gos << "node" << edge.first.first << " -> " << "node"
        << edge.first.second << " [label=\"" << edge.second << "\"];\n";
  }
  gos << "}" << endl;
}