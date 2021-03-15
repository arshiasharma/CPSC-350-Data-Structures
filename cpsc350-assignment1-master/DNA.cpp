//header file - for the def of the class

#include "DNA.h"
#include <iostream> //input/output
#include <fstream> //reading in and out of files
#include <cmath> //for squaring and square root
#include <math.h> //for pi
#include <algorithm> //for random_shuffle

using namespace std; //namespace(collection of classes) std = standard

//constructor implementation
DNA::DNA(){
  sequence = "";
  line = "";
  final = "";
  count = 0;
  sum = 0;
  mean = 0.0;
  variance = 0.0;
  stdDev = 0.0;
  countA = 0;
  countT = 0;
  countC = 0;
  countG = 0;
  countAA = 0;
  countAT = 0;
  countAC = 0;
  countAG = 0;
  countTA = 0;
  countTT = 0;
  countTC = 0;
  countTG = 0;
  countCA = 0;
  countCT = 0;
  countCC = 0;
  countCG = 0;
  countGA = 0;
  countGT = 0;
  countGC = 0;
  countGG = 0;
  freqA = 0.0;
  freqT = 0.0;
  freqC = 0.0;
  freqG = 0.0;
  freqAA = 0.0;
  freqAT = 0.0;
  freqAC = 0.0;
  freqAG = 0.0;
  freqTA = 0.0;
  freqTT = 0.0;
  freqTC = 0.0;
  freqTG = 0.0;
  freqCA = 0.0;
  freqCT = 0.0;
  freqCC = 0.0;
  freqCG = 0.0;
  freqGA = 0.0;
  freqGT = 0.0;
  freqGC = 0.0;
  freqGG = 0.0;
}

//destructor
DNA::~DNA(){
}

//method to calculate all the mathematically formulas: sum, mean, variance, stand deviation, relative probability
void DNA::calcOutput(string input){

  //reading into a text file - see README for sources
  ifstream infile(input);

  //looping through the file - check README for source
  while (getline(infile, line)){
    for(int i = 0; i < line.length(); ++i){ //for loop

      char nuc = toupper(line[i]); //uppercase everything, example in class for lowercase
      char bigram = toupper(line[i+1]);

      //count for A and bigrams AA, AT, AC, AG
      if (nuc == 'A'){
        countA++;
        if(bigram == 'A'){
          countAA++;
        }else if(bigram == 'T'){
          countAT++;
        }else if(bigram == 'C'){
          countAC++;
        }else if(bigram== 'G'){
          countAG++;
        }
        sum++; //keeping track of the characters in the file
      }

      //count for T and bigrams TA, TT, TC, TG
      if (nuc == 'T'){
        countT++;
        if(bigram == 'A'){
          countTA++;
        }else if(bigram == 'T'){
          countTT++;
        }else if(bigram == 'C'){
          countTC++;
        }else if(bigram == 'G'){
          countTG++;
        }
        sum++; //keeping track of the characters in the file
      }

      //count for C and bigrams CA, CT, CC, CG
      if (nuc == 'C'){
        countC++;
        if(bigram == 'A'){
          countCA++;
        }else if(bigram == 'T'){
          countCT++;
        }else if(bigram == 'C'){
          countCC++;
        }else if(bigram == 'G'){
          countCG++;
        }
        sum++; //keeping track of the characters in the file
      }

      //count for G and bigrams GA, GT, GC, GG
      if (nuc == 'G'){
        countG++;
        if(bigram == 'A'){
          countGA++;
        }else if(bigram == 'T'){
          countGT++;
        }else if(bigram == 'C'){
          countGC++;
        }else if(bigram == 'G'){
          countGG++;
        }
        sum++; //keeping track of the characters in the file
      }
    }
    count++; //keeping track of the amount of lines in the file
  }

  //calculations of mean and relative frequencies

  mean = float(sum) / float(count);
  freqA = float(countA) / float(sum);
  freqT = float(countT) / float(sum);
  freqC = float(countC) / float(sum);
  freqG = float(countG) / float(sum);
  freqAA = float(countAA) / float((sum/2));
  freqAT = float(countAT) / float((sum/2));
  freqAC = float(countAC) / float((sum/2));
  freqAG = float(countAG) / float((sum/2));
  freqTA = float(countTA) / float((sum/2));
  freqTT = float(countTT) / float((sum/2));
  freqTC = float(countTC) / float((sum/2));
  freqTG = float(countTG) / float((sum/2));
  freqCA = float(countCA) / float((sum/2));
  freqCT = float(countCT) / float((sum/2));
  freqCC = float(countCC) / float((sum/2));
  freqCG = float(countCG) / float((sum/2));
  freqGA = float(countGA) / float((sum/2));
  freqGT = float(countGT) / float((sum/2));
  freqGC = float(countGC) / float((sum/2));
  freqGG = float(countGG) / float((sum/2));

  //variane and standard deviation calculations - reading into the file again

  ifstream newfile(input);

  float x = 0.0;
  float varSum = 0.0;
  while (getline(newfile, line)){
    for(int i=0; i < line.length(); ++i){
      x = pow((line.length() - mean), 2); //mathematical function for powers - check README for sources
    }

    varSum+= x;
    variance = (varSum / (count-1));
    stdDev = sqrt(variance); //mathematical function for the square root, check README
  }
}

//method for writing the data to arshiasharma.out text file and Guassian distribution calculations
void DNA::fileOutput(string file){

  //writing to a file
  ofstream answerFile;

  //openning arshiasharma.out and not overriding what's currently in the file; appending the data
  answerFile.open ("arshiasharma.out", fstream::app); //check README

  //calling function to get the member variables and values
  calcOutput(file);

  answerFile << "\nThe data for " << file << " is: " << endl;
  answerFile << "\nThe sum is: " << sum << "\nThe mean is: " << mean  << "\nThe variance is " << variance << "\nThe standard deviation is " << stdDev << endl;
  answerFile << "\nThe relative frequency of A is: " << freqA << "\nThe relative frequency of T is: " << freqT <<"\nThe relative frequency of C is: " << freqC <<"\nThe relative frequency of G is: " << freqG << endl;
  answerFile << "\nThe relative frequency of AA is " << freqAA << "\nThe relative frequency of AT is " << freqAT << "\nThe relative frequency of AC is " << freqAC << "\nThe relative frequency of AG is " << freqAG << endl;
  answerFile << "\nThe relative frequency of TA is " << freqTA << "\nThe relative frequency of TT is " << freqTT << "\nThe relative frequency of TC is " << freqTC << "\nThe relative frequency of TG is " << freqTG << endl;
  answerFile << "\nThe relative frequency of CA is " << freqCA << "\nThe relative frequency of CT is " << freqCT << "\nThe relative frequency of CC is " << freqCC << "\nThe relative frequency of CG is " << freqCG << endl;
  answerFile << "\nThe relative frequency of GA is " << freqGA << "\nThe relative frequency of GT is " << freqGT << "\nThe relative frequency of GC is " << freqGC << "\nThe relative frequency of GG is " << freqGG << "\n" << endl;

  answerFile << "The 1000 strings based on the Guassian distribution is as follows: " << endl;

  answerFile.close();

  //new stream so arshiasharma.out does not get overwritten, start of Guassian calculations
  ofstream answerFile2;
  answerFile2.open ("arshiasharma.out", fstream::app);

    //loop for 1000 strings
    for(int i = 0; i <= 1000; ++i){

      //constants A and B for the formula below - uses random function
      double a = ((double) rand() / (RAND_MAX)); //see README
      double b = ((double) rand() / (RAND_MAX));

      //functions for C and D formulas in assignment - README
      double c = sqrt(-2 * log(a)) * cos(2* M_PI * b);
      int d = abs(ceil((stdDev * c) + mean)); //whole number so we don't have half a nucelotide
      if(d == 0){
        d = 1;
      }

      //rounds the number up to a whole number so we dont have half a nucelotide - README for rand()
      int newFreqA = round(freqA * d);
      int newFreqT = round(freqT * d);
      int newFreqC = round(freqC * d);
      int newFreqG = round(freqG * d);

      //loop to get a string of d length and outputs in to the file
      for(int j = 0; j < d; ++j){

        //loop adds the correct amount of characters to the string for each line
        if(0 < newFreqA){
          sequence += 'A';
          newFreqA--;
        }if(0 < newFreqT){
          sequence += 'T';
          newFreqT--;
        }if(0 < newFreqC){
          sequence += 'C';
          newFreqC--;
        }if(0 < newFreqG){
          sequence += 'G';
          newFreqG--;

        //case for if d = 1 since freqx * 1 = freqx so have to account for that one character string
        }if(d == 1){
          if(freqA > freqC && freqA > freqG && freqA > freqT){
            sequence += 'A';
          }else if(freqT > freqC && freqT > freqG && freqT > freqA){
            sequence += 'T';
          }else if(freqC > freqT && freqC > freqG && freqC > freqA){
            sequence += 'C';
          }else if(freqG > freqT && freqG > freqC && freqG > freqA){
            sequence += 'G';
          }
        }
      }

      //shuffles the string to randomize the nucelotide string; uses <algorithm>
      random_shuffle (sequence.begin(), sequence.end()); //Check README for random_shuffle

      //writes to the output file
      answerFile2 << sequence << endl;
      sequence = "";
    }
    //closes the file
    answerFile2.close();
}
