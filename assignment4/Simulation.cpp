#include "Simulation.h"
#include <fstream> //reading in and out of file
#include <iostream>

using namespace std;

//default constructor
Simulation::Simulation(){
  myQueue = new GenQueue<Student>();
  size = 0;
  studentSize = -1;
  time = 0;
  windowTime = 0;
  students = 0;
  studentCount = 0;
  min = 0;
  windowCount = 0;
}

//destructor
Simulation::~Simulation(){
  delete myQueue;
}

//conducting the simulation for the program
void Simulation::simulation(string file){

  int count = 0; //keeping track of when the loop should read into the file again
  string line; //variable assigned to the line of the file
  int var = 1; //variable keeping track if there's a correct number of student objects created
  Student *tempStudent = new Student(); //temp student
  int firstline = -1; //the first time in the file variable
  int count4[size]; //counting how many windows were occupied in one time
  int count4T = -1; //count4 variable count
  int start = 0; //variable for the first time in the file

  //opening up the file and reading into it
  ifstream infile(file);

  //loop going through the file
  while(getline(infile, line)){

    //handes the first line of the file to know the number of windows
    if(count == 0){

      //assigns the number of windows
      size = stoi(line);

      //Array of windows
      arrWindow[size];
      for(int i = 0; i < size; i++){
        arrWindow[i] = new Window();
      }

      count++;
      continue;

    //time that student arrives at registar
    }if(count == 1){
      time = stoi(line);
      count++;
      continue;

    //creating the correct number of student objects
    }if(count == 2){
      students = stoi(line);
      studentCount += students;
      count++;
      continue;

    }if(count == 3){
      windowTime = stoi(line);

      //creating a new student object
      Student *s = new Student(windowTime);

      //inserting the student to the queue
      myQueue->insert(s);

      //continue to next line in file to get all student times
      if(var < students){
        var++;
        continue;

      //if all students have been accounted for, go to next condition
      }else if(var == students){
        count = 4;
        var = 1;
      }
    }

    //handles the students at the windows
    if(count = 4){

      firstline++;

      if(firstline == 0){
        for(int i = 0; i < size; i++){
          arrWindow[i]->addWaitTime(time);
        }
        start = time;
      }else{
        for(int i = 0; i < size; i++){

          if(arrWindow[i]->isOccupied() == false){
            arrWindow[i]->addWaitTime(time);
          }
        }
      }

      //var is now 1, it will now assign each student to a window
      while(var <= students){

        //if queue is empty, break
        if(myQueue->isEmpty()){
          break;

        //if the queue is not empty
        }else if(myQueue->isEmpty() == false){

          //the first student is removed
          tempStudent = myQueue->remove();
          studentSize++;
          var++;

          //if the windows are all full
          //have to find the window that the student will eventually go too
          if(windowCount == size){

            int w = 0; //keeps track of the window
            int oTime[size]; //array of occupiedtime of a window

            //added the occupied times to the array and subtracting the current time to find min
            for(int i = 0; i < size; i++){
              if(firstline == 0){
                oTime[i] = arrWindow[i]->getOccupiedTime();
              }else if(arrWindow[i]->getCurrentlyOccupied() == true){
                oTime[i] = (arrWindow[i]->getOccupiedTime() + time) - start;
              }else if(arrWindow[i]->getCurrentlyOccupied() == false){
                oTime[i] = (arrWindow[i]->getOccupiedTime() - time) + start;
              }
            }

            min = oTime[0];

            //finding the minimum occupiedtime
            for(int i = 1; i < size; i++){

              if(oTime[i] < min){
                min = oTime[i];
                w = i;
              }
            }

            if(min < 0){
              min = 0;
            }

            //adding the waittime to the student
            tempStudent->addTime(min);

            //adding the occupied time to the window
            arrWindow[w]->addOccupiedTime(tempStudent->getTime());
            arrWindow[w]->currentlyOccupied();

            //tempStudent is added to the array
            arrStudent[studentSize] = tempStudent;
          }

          //going through each window
          for(int i = 0; i < size; i++){

            //if the window is not occupied
            if(arrWindow[i]->isOccupied() == false){

              arrWindow[i]->currentlyOccupied();

              count4T++;

              //counting how many windows were occupied in one time
              count4[count4T] = i;

              //added zero to the wait time if the student has no waittime
              tempStudent->addTime(0);

              //adding student to the array of students
              arrStudent[studentSize] = tempStudent;

              //the window is occupied
              arrWindow[i]->updateT();

              //adding the occupiedtime to the window
              arrWindow[i]->addOccupiedTime(tempStudent->getTime());

              windowCount++;
              break;

            //if the occupiedtime - time is less than or equal to zero
            //window is than free
            }if(arrWindow[i]->getOccupiedTime() - time <= 0){

              //window is now free
              arrWindow[i]->updateF();
              windowCount--;
            }
          }

          //if var is greater than or ewual to students
          //go to count 5 condition
          if(var >= students){
            count = 5;
          }
        }
      }

    //condition 5 which goes back to count 1 for new time and students
    }if(count == 5){
      count = 1;
      var = 1;
      count4T = -1;

      for(int i = 0; i < size; i++){

        if(arrWindow[i]->isOccupied() == false){
          arrWindow[i]->addWaitTime(time);
        }

        arrWindow[i]->notCurrentlyOccupied();
        //if the window is still avaliable, add the time of waittime
      }
      for(int i = 0; i < size; i++){
        count4[i] = -1;
      }
      continue;
    }
  }

  //if var does not equal 1 from count 5, that means that the file ended unexpectedly
  //the file is not written correctly
  if(var != 1){
    cout << endl;
    cout << "Error in text file, please double check" << endl;
    cout << endl;
    return;
  }

  //going to the calculations methods
  calculations();
}


//calculating the end products for the user
void Simulation::calculations(){

  //mean of Student waittime

  cout << endl;
  float n = 0;
  float meanCount = 0;

  //gets waittime for the students to calculate the mean of student waittimes
  for(int i = 0; i < studentCount; i++){
    n += arrStudent[i]->getWaitTime();
    meanCount++;
  }

  //handles a 0/n case
  if(n == 0.0){
    n = 0.0;

  //computes to mean is n isnt 0
  }else{
    n = n/meanCount;
  }
  cout << "The mean of student wait times is: " << n << endl;

  //median of Student waitTime

  float median = 0.0f;
  int medianPos;
  int medianArr[studentCount]; //array of waittimes in order

  //adding waittimes to an array
  for(int i = 0 ; i < studentCount; i++){
    medianArr[i] = arrStudent[i]->getWaitTime();
  }

  //putting the array in order
  for(int i = 0; i < studentCount; i++ ){
    for(int j = i + 1; j < studentCount ; j++){
      if(medianArr[i] < medianArr[j]){
        median = medianArr[i];
        medianArr[i] = medianArr[j];
        medianArr[j] = median;
      }
    }
  }

  studentSize++;

  //checking if there is a remainder
  medianPos = studentSize%2;

  //if there is a remainder
  if(medianPos == 1){
    medianPos = (studentSize/2);
    cout << "The median for student wait time is: " << medianArr[medianPos] << endl;
  }else{
    medianPos = (studentSize/2);
    median = ((medianArr[medianPos + 1] + medianArr[medianPos]) /2);
    cout << "The median for student watitime: " << median << endl;
  }

  //longest Student waittime

  cout << "The longest Student Wait Time: " << medianArr[0] << endl;

  //The number of students waiting over 10 minutes

  int student10 = 0;
  for(int i = 0 ; i < studentCount ; i++){
    if (medianArr[i] >= 10){
      student10++;
    }
	}
  cout << "The number of Student Wait Time over 10 minutes: " << student10 << endl;
  cout << endl;

  //The mean window idle time

  int meanWindow[size];
  float windowSum = 0.0;

  //gets the waittimes for windows
  for(int i = 0; i < size; i++){
    meanWindow[i] = arrWindow[i]->getWaitTime();
  }

  for(int i = 0; i < size; i++){
    windowSum += meanWindow[i];
  }

  float windowMean = windowSum / size;

  cout << "The mean window idle time is: " << windowMean << endl;

  //The longest window idle time

  int tempWindow = 0;

  //puts the array in order
  for(int i = 0; i < size; i++ ){
    for(int j = i + 1; j < size; j++){
      if(meanWindow[i] < meanWindow[j]){
        tempWindow = meanWindow[i];
        meanWindow[i] = meanWindow[j];
        meanWindow[j] = tempWindow;
      }
    }
  }

  cout << "The longest window idle time is: " << meanWindow[0] << endl;

  //Number of windows idle for over 5 minutes.

  int window5 = 0;
  for(int i = 0 ; i < size; i++){
    if (meanWindow[i] >= 5){
      window5++;
    }
	}
  cout << "The number of Window Wait Time over 5 minutes: " << window5 << endl;
  cout << endl;

}
