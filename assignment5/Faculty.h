#include <iostream>
#include "GenDoublyLinkedList.cpp"
using namespace std;

class Faculty{
  public:
      Faculty(); //default
      Faculty(int i, string n, string l, string d, int ad); //overload constructor
      Faculty(int i, string n, string l, string d, GenDoublyLinkedList<int> *ad); //overload constructor
      ~Faculty(); //destructor

      //member variables
      int id;
      string name;
      string level;
      string department;
      GenDoublyLinkedList<int> *advisees;

      void getInfo(); //prints data of the object
      string getFile(); //prints data of object as a string
      int getID(); //returns the ID number of faculty
      GenDoublyLinkedList<int>* getAdvisees(); //returns the advisees table
      int setAdvisees(int pos); //deletes the advisee at the inputted position
      void addAdvisee(int ad); //adds to the advisees list
      void printAdvisees(); //prints the advisees ID numbers
};
