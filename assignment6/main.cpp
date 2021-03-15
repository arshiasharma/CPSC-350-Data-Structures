#include "Simulation.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv){

  //checking if the user inputed correctly
  if(argc == 1){
    cout << "Enter the file you want checked after ./assignment6.out" << endl;
    return 0;
  }

  string file = argv[1]; //arg value

  //sorting takes place in simulation
  Simulation *s = new Simulation();
  s->simulation(file);

}
