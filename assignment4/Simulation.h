#include "GenQueue.cpp"
#include "Student.h"
#include "Window.h"
#include <iostream>

using namespace std;

class Simulation{
  public:
    Simulation(); //constructor
    ~Simulation(); //destructor

    void simulation(string file); //method for handling all simulations
    void calculations(); //calculating the calculations needed for the end product

  private:
    GenQueue<Student> *myQueue; //queue
    int size; //number of windows
    int studentSize; //number of all students who came to registar
    int time; //the time students arrive to the registar
    int windowTime; //time spent at each window by the student
    int students; //number of students who come at a certain time
    Student *arrStudent[100]; //array of students waittimes
    int studentCount; //number of total students that come in the file
    Window *arrWindow[100]; //array of window waittimes
    int min; //minimum waittime for a certain window
    int windowCount; //counting the windows that are in use
};
