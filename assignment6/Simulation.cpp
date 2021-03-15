#include "Simulation.h"
#include <fstream> //reading in and out of file
#include <iostream>
#include <ctime> //for the time
#include <time.h>
#include <chrono>

using namespace std;

Simulation::Simulation(){
}

Simulation::~Simulation(){
    delete [] bubbleArr;
    delete [] insertArr;
    delete [] quickArr;
    delete [] selectionArr;
    delete [] mergeArr;
}

void Simulation::simulation(string file){

  int count = 0;
  string line = "";

  //reading into the file
  ifstream infile(file);

  int i = 0;


  while(getline(infile, line)){

    //reads first line in file to find the number of elements
    if(count == 0){
      n = stoi(line);
      count++;
      bubbleArr = new double[n];
      insertArr = new double[n];
      quickArr = new double[n];
      selectionArr = new double[n];
      mergeArr = new double[n];
      continue;
    }

    //making all the arrays to sort
    if(count == 1){
      bubbleArr[i] = stod(line);
      insertArr[i] = stod(line);
      quickArr[i] = stod(line);
      selectionArr[i] = stod(line);
      mergeArr[i] = stod(line);
      i++;
      continue;
    }
  }

  //bubble sort
  cout << endl;
  cout << "Bubble Sort" << endl;

  //getting the time when it starts
  auto start = std::chrono::steady_clock::now();
  bubbleSort(bubbleArr);

  //getting the time when it ends
  auto end = std::chrono::steady_clock::now();

  //subtracts end time with start
  double time = double(std::chrono::duration_cast<std::chrono::nanoseconds> (end-start).count());

  //divides time by 1e9 to get the time in seconds
  cout << "Time duration: " << (time / 1e9) << endl;

  cout << endl;

  //selection sort
  cout << "Selection Sort" << endl;

  //getting the time when it starts
  start = std::chrono::steady_clock::now();
  selectionSort(selectionArr, n);

  //getting the time when it ends
  end = std::chrono::steady_clock::now();

  //subtracts end time with start
  time = double(std::chrono::duration_cast<std::chrono::nanoseconds> (end-start).count());
  cout << "Time duration: " << (time / 1e9) << endl;

  //insert sorting
  cout << endl;
  cout << "Insert Sort" << endl;

  //getting the time when it starts
  start = std::chrono::steady_clock::now();
  insertSort(insertArr);

  //getting the time when it ends
  end = std::chrono::steady_clock::now();

  //subtracts end time with start
  time = double(std::chrono::duration_cast<std::chrono::nanoseconds> (end-start).count());
  cout << "Time duration: " << (time / 1e9) << endl;

  //quickSort
  cout << endl;
  cout << "Quick Sort" << endl;

  //getting the time when it starts
  start = std::chrono::steady_clock::now();
  quickSort(quickArr, 0, n-1);

  //getting the time when it ends
  end = std::chrono::steady_clock::now();
  time = double(std::chrono::duration_cast<std::chrono::nanoseconds> (end-start).count());
  cout << "Time duration: " << (time / 1e9) << endl;

  //mergeSort
  cout << endl;
  cout << "Merge Sort" << endl;

  //getting the time when it starts
  start = std::chrono::steady_clock::now();
  mergeSort(mergeArr, 0, n-1);

  //getting the time when it ends
  end = std::chrono::steady_clock::now();

  //subtracts end time with start
  time = double(std::chrono::duration_cast<std::chrono::nanoseconds> (end-start).count());
  cout << "Time duration: " << (time / 1e9) << endl;
}

//Bubble sort code
void Simulation::bubbleSort(double myArray[]){

  //compares each index with its next element
  for(int i = 0; i < n; ++i){
    double temp = 0;
    for(int j = i; j < n-1; ++j){
      if(myArray[j] > myArray[j+1]){
        temp = myArray[j+1];
        myArray[j+1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
}

//Selection Sort code
void Simulation::selectionSort(double arr[], int n){
  int i, j, minIndex, tmp;

  //minIndex is compared with all other elements of the array
  //switches it with the lowest element in the array
  for(i = 0; i < n-1; i++){
    minIndex = i;

    for(j = i+1; j < n; j++){
      if(arr[j] < arr[minIndex]){
        minIndex = j;
      }

      if(minIndex != i){
        tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
      }
    }
  }
}

//Insert Sort - partial sorted
//moves lowest element to the left
void Simulation::insertSort(double arr[]){
  for(int j = 1; j < n; ++j){ //marker
    double temp  = arr[j]; //store marker item
    int k = j;
    while(k > 0 && arr[k-1] >= temp){ //while the thing to the left is larger, shift
      arr[k] = arr[k-1];
      --k;
    }
    arr[k] = temp; //put marked item in right spot
  }
}


void Simulation::quickSort(double myArray[], int l, int g){

  //if lowest index is lower than the greatest
  if (l < g){
  //step 1. dividing
    int div = divide(myArray, l, g);

    //Recursively sorting L and G
    quickSort(myArray, l, div - 1);
    quickSort(myArray, div + 1, g);
    }
  }

//dividing the array into small parts recursively to sort
int Simulation::divide(double myArray[], int l, int g){

  int knownIndex = l; // keeping track of the known index
  double temp;

  //for all elements less than the pivot - myArray[g]
  for(int i = l; i <= g-1; i++){
    if(myArray[i] < myArray[g]){
      temp = myArray[knownIndex];
      myArray[knownIndex] = myArray[i];
      myArray[i] = temp;

      knownIndex++;
    }
  }

  //pivot changes to the index known
  temp = myArray[knownIndex];
  myArray[knownIndex] = myArray[g];
  myArray[g] = temp;

  return knownIndex;
}

//merge Sort - splits the array into smaller arrays and sorts
void Simulation::mergeSort(double myArray[], int s, int e){
  if(s < e){

    //splits the array into two arrays
    int mid = ((s + e) / 2);

    //recursively sorting
    mergeSort(myArray, s, mid);
    mergeSort(myArray, mid + 1, e);

    //sorts the newly split arrays
    mergeS(myArray, s, mid, e);
  }
}

//split the array into smaller arrays
void Simulation::mergeS(double myArray[], int s, int m, int e){

//keeping track of the variables
int start = s;
int end = m + 1;

//new array and position
double Arr[(e - s) + 1];
int x = 0;

//for loop sorting elements in the new array
for(int i = s; i <= e; i++){

  if(start > m){
    //checks if first sort of the array is over
    myArray[x++] = myArray[end++];
  }

  //checks if second sort is over
   else if(end > e){
     myArray[x++] = myArray[start++];
   }

   //which element is smaller
   else if(myArray[start] < myArray[end]){
     myArray[x++] = myArray[start++];
   }
   else{
     myArray[x++] = myArray[end++];
   }
 }

 //array now sorted
  for(int j = 0; j < x; j++) {
     myArray[s++] = myArray[j] ;
  }
}
