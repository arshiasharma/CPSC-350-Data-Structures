#include "SyntaxChecker.h"
#include <fstream> //reading in and out of files
#include <iostream>

using namespace std;

int main (int argc, char **argv){

  bool loop = true;
  bool output = true;
  string answer;

  if(argc == 1){
    cout << "Enter the file you want checked after ./assignment3.out" << endl;
    return 0;
  }

  string test = argv[1]; //arg value

  //In case the user wants to check another file
  while(loop){

    if(output){
      SyntaxChecker* s = new SyntaxChecker();
      bool count = s->simulation(test);

      if(count){
        cout << "Do you wish to check another file: y/n: ";
        cin >> answer;

        if(answer == "y"){
          cout << "Enter file name: ";
          cin >> test;
          loop = true;
        }if(answer == "n"){
          loop = false;
        }
      }else{
        return 0;
      }
    }
  }
}
