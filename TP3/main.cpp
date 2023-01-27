#include<iostream>

#include "Statistic.h"

using namespace std;

int main(int argc, char* argv[]){
  Statistic stat(argv[1]);
  stat.displayCount();
  return 0;
}
