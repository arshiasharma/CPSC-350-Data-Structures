//header file - for the def of the class

#include "DNA.h"
#include <iostream>
#include <fstream> //reading in and out of files

using namespace std;

//main method with command line inputs
int main(int argc, char** argv){
  if(argc > 1){ //arg count

    string test = argv[1]; //arg value
    char answer;
    bool loop = true;

    DNA* d = new DNA(); //new operator

    //opening and writing to a text file
    ofstream output;

    //will override what is in the file currently; will keep all the data that will be written until the program is executed again
    output.open ("arshiasharma.out");
    output << "Arshia Sharma  \nID Number: 2137340" <<endl;
    output.close();

    //having the object compute the calculations and send data to arshiasharma.out

    d->fileOutput(test); //pointer
    delete d; //deletes the object

    //to account for multiple files
    while(loop){

      DNA* d2 = new DNA(); //new object to avoid confusion

      cout << "\nDo you wish to continue with another file: enter y/n: ";
      cin >> answer;

      if(answer == 'y' || answer == 'Y'){

        cout << "Enter new text file: ";
        cin >> test;
        d2->fileOutput(test);
        delete d2;

      }else if(answer == 'n' || answer == 'N'){
        cout << "\nYour data is stored under arshiasharma.out" << endl;
        cout << "Goodbye" << endl;
        loop = false;
        delete d2;
      }
    }
  }
}
