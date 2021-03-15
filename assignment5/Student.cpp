#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

//default constructor
Student::Student(){
  id = 0;
  name = "";
  levelField = "";
  major = "";
  gpa = 0.0;
  facultyAdvisor = 0;
}

//overload constructor
Student::Student(int i, string n, string l, string m, double g, int f){
  id = i;
  name = n;
  levelField = l;
  major = m;
  gpa = g;
  facultyAdvisor = f;
}

//destructor
Student::~Student(){
}

//prints the info of the Student
void Student::getInfo(){
  cout << "\nID: " << id;
  cout << "\nName: " << name;
  cout << "\nLevel Field: " << levelField;
  cout << "\nMajor: " << major;
  cout << "\nGPA: " << gpa;
  cout << "\nFaculty Advisor ID: " << facultyAdvisor;
  cout << "\n";
}

//prints the info of the Student as a string
string Student::getFile(){
  string temp = "";
  temp += to_string(id);
  temp += "\n" + name;
  temp += "\n" + levelField;
  temp += "\n" + major;
  temp += "\n" + to_string(gpa);
  temp += "\n" + to_string(facultyAdvisor);

  return temp;
}

//return the facultyAdvisor's ID number
int Student::getID(){
  return facultyAdvisor;
}

//returns student ID
int Student::returnID(){
  return id;
}

//adds the facultyAdvisor to the student
void Student::changeFacultyAdvisor(int f){
  facultyAdvisor = f;
}
