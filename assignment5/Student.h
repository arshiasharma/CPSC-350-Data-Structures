#include <iostream>

using namespace std;

class Student{
  public:
      Student(); //default constructor
      Student(int i, string n, string l, string m, double g, int f); //overload constructor
      ~Student(); //destructor

      //member variables
      int id;
      string name;
      string levelField;
      string major;
      double gpa;
      int facultyAdvisor;


      void getInfo(); //prints the info of the Student
      string getFile(); //prints the info of the Student as a string
      int getID(); //return the facultyAdvisor's ID number
      int returnID(); //returns student ID
      void changeFacultyAdvisor(int f); //adds the facultyAdvisor to the student

};
