#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <istream>
using namespace std;

int main (){

  string line;
  int count = 0;

  //two files with the data of the trees
  string file = "studentTable";
  string file2 = "facultyTable";

  //reading into the file
  ifstream infile(file);

  //if the file has content, then we know they have data
  while(getline(infile, line)){
    Simulation *s = new Simulation(file, file2);
    s->simulation();
    return 0;
  }

  //if the files are empty
  Simulation *s = new Simulation();
  s->simulation();
}
