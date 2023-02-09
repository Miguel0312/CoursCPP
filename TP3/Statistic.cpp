#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include<utility>
#include<algorithm>

#include "Statistic.h"
#include "Log.h"

using namespace std;

Statistic::Statistic(vector<Log> logVector, bool grapheF, string grapheFi):
logs(logVector), grapheFlag(grapheF), grapheFile(grapheFi){
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
      idRef = id;
    }

    map<string, int>::iterator posTarget = nodes.find(log.getTargetURL());
    if(posTarget != nodes.end())
      idTarget = posTarget->second;
    else{
      nodes[log.getTargetURL()] = ++id;
      idTarget = id;
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

bool comp(const pair<int, string>& a, const pair<int, string>& b){
  if(a.first != b.first)
    return a.first > b.first;
  return a.second < b.second;
}

void Statistic::displayCount(){
  map<string, int> count;
  for(int i = 0; i<(int)logs.size();i++){
    string targetURL = logs[i].getTargetURL();
    auto targetLocation = count.find(targetURL);
    if(targetLocation != count.end()){
      targetLocation->second++;
    }
    else{
      count[targetURL] = 1;
    }
  }

  if(grapheFlag){
    cout << "Dot-file " << grapheFile << " generated" << endl;
    generateGraph(grapheFile);
  }

  set<pair<int,string>, decltype(comp)*> order(comp);
  for(auto it = count.begin(); it!=count.end(); it++){
    order.insert(make_pair(it->second,it->first));
  }

  int maxLines = 10, lines = 0;
  auto it = order.begin();
  while(lines < maxLines && it != order.end()){
    int cur = it->first;
    while(it != order.end() && it->first == cur){
      cout << it->second << " (" << it->first << " hits)" << endl;
      lines++;
      it++;
    }
  }
}

