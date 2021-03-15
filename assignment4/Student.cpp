#include "Student.h"
#include <iostream>

using namespace std;

//default constructor
Student::Student(){
  time = 0;
  waitTime = 0;
}

//overload constructor
Student::Student(int t){
  time = t;
  waitTime = 0;
}

//destructor
Student::~Student(){
}

//adding student waitTime
void Student::addTime(int t){
  waitTime += t;
}

//returns the time the student gets in line
int Student::getTime(){
  return time;
}

//returns the waittime of the student
int Student::getWaitTime(){
  return waitTime;
}
