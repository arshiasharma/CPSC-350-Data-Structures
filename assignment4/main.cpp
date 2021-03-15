#include "Simulation.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv){

  //checking if the file input is correct (one file)
  //check if the file is correctly inputted in the simulation file
  if(argc == 1){
    cout << "Enter the file you want checked after ./assignment4.out" << endl;
    return 0;
  }

  string file = argv[1]; //arg value

  //logic and calculations take place in simulation file
  Simulation* s = new Simulation();
  s->simulation(file);

}
