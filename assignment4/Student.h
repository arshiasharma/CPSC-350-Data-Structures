#include <iostream>

using namespace std;

class Student{
  public:
      Student();
      Student(int time);
      ~Student();

      void addTime(int t); //adding Student waittime
      int getTime(); //returning time 
      int getWaitTime(); //returning waittime

      int waitTime;
      int time;

};
