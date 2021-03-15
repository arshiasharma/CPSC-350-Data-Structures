//header file - for the def of the class

#include <iostream>

using namespace std; //namespace(collection of classes) std = standard

//creating the class DNA
class DNA{

  //making the member variables private to stay with OOP
  private:
    string sequence;
    string line;
    string final;
    int count;
    int sum;
    float mean;
    float variance;
    float stdDev;
    int countA;
    int countT;
    int countC;
    int countG;
    int countAA;
    int countAT;
    int countAC;
    int countAG;
    int countTA;
    int countTT;
    int countTC;
    int countTG;
    int countCA;
    int countCT;
    int countCC;
    int countCG;
    int countGA;
    int countGT;
    int countGC;
    int countGG;
    float freqA;
    float freqT;
    float freqC;
    float freqG;
    float freqAA;
    float freqAT;
    float freqAC;
    float freqAG;
    float freqTA;
    float freqTT;
    float freqTC;
    float freqTG;
    float freqCA;
    float freqCT;
    float freqCC;
    float freqCG;
    float freqGA;
    float freqGT;
    float freqGC;
    float freqGG;

  //constructor, destructor, and methods
  public:
    DNA(); //constructor
    ~DNA(); //destructor

    //methods to complete the calculations and output to arshiasharma.out file
    void calcOutput(string input);
    void fileOutput(string file);
};
