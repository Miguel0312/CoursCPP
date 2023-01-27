#include <string>
#include <set>
#include <vector>
#include <fstream>
#include<utility>
#include<algorithm>

#include "Statistic.h"
#include "Log.h"

using namespace std;

Statistic::Statistic(string logFileName){
  // TODO: parse file and generate logs
  ifstream logFile;
  logFile.open(logFileName);
  string logActuel;
  while(getline(logFile, logActuel)){
    logs.emplace_back(logActuel);
  }

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

bool comp(const pair<string, int> &a, const pair<string,int> &b){
  if(a.second !=b.second){
    return a.second < b.second;
  }
  return a.first < b.first;
}

void Statistic::displayCount(){
  map<string, int> count;
  for(int i = 0; i<logs.size();i++){
    string targetURL = logs[i].getTargetURL();
    auto targetLocation = count.find(targetURL);
    if(targetLocation != count.end()){
      targetLocation->second++;
    }
    else{
      count[targetURL] = 1;
    }
  }

  set<pair<string,int>> order;
  for(auto it = count.begin(); it!=count.end(); it++){
    order.insert(make_pair(it->first,it->second));
  }
  sort(order.begin(), order.end(), comp);
  size_t maxLines =10;
  int lines = min(order.size(), maxLines);
  auto it = count.begin();
  advance(it, lines-1);
  int maxCount = it->second;
  advance(it,1);
  while(it!=count.end() && it->second == maxCount){
    lines++;
  }

}

