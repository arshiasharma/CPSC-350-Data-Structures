#include "BST.cpp"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.cpp"
#include <iostream>

using namespace std;

class Simulation{
  public:
    Simulation(); //default constructor
    Simulation(string file, string file2); //overload constructor
    ~Simulation(); //destructor

    void simulation(); //method with all the configurations of the program

  //member variables
  private:
    BST<Student> *masterStudent;
    BST<Faculty> *masterFaculty;
    GenStack<Student> *rollBackStudent;
    GenStack<Faculty> *rollBackFaculty;
    GenStack<int> *rollBackNum;
    int choice;
    int studentID;
    int facultyID;
    bool stud;

    int undo;
};
