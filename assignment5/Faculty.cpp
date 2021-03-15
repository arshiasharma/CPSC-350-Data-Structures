#include "Faculty.h"
#include <iostream>
#include <string>

using namespace std;

//default constructor
Faculty::Faculty(){
  id = 0;
  name = "";
  level = "";
  department = "";
  advisees = new GenDoublyLinkedList<int>();
}

//overload constructor
Faculty::Faculty(int i, string n, string l, string d, int ad){
  id = i;
  name = n;
  level = l;
  department = d;
  advisees = new GenDoublyLinkedList<int>();
  advisees->insertBack(ad);
}

//overload constructor
Faculty::Faculty(int i, string n, string l, string d, GenDoublyLinkedList<int> *ad){
  id = i;
  name = n;
  level = l;
  department = d;
  advisees = ad;
}

//destructor
Faculty::~Faculty(){
  delete advisees;
}

//printing the info of faculty
void Faculty::getInfo(){
  cout << "\nID: " << id;
  cout << "\nName: " << name;
  cout << "\nLevel: " << level;
  cout << "\nDepartment: " << department;
  cout << "\nAdvisees ID: " << endl;
  advisees->printList();
}

//printing the info of the faculties as a string
string Faculty::getFile(){
  string temp = "";
  temp += to_string(id);
  temp += "\n" + name;
  temp += "\n" + level;
  temp += "\n" + department;
  temp += advisees->returnList();

  return temp;
}

//returns the ID of faculty
int Faculty::getID(){
  return id;
}

//returns the list of advisees
GenDoublyLinkedList<int>* Faculty::getAdvisees(){
  return advisees;
}

//prints the list of advisees
void Faculty::printAdvisees(){
  advisees->printList();
}

//deletes an advisee
int Faculty::setAdvisees(int pos){
  return advisees->deletePos(pos);
}

//adds an advisee
void Faculty::addAdvisee(int ad){
  advisees->insertBack(ad);
}
