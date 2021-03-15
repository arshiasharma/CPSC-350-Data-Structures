#include <iostream>
using namespace std;

class Window{
  public:
    Window();
    Window(int i);
    ~Window();

    bool isOccupied(); //checks if the window is occupied
    void addOccupiedTime(int o); //adds occupied time
    void updateT(); //updates if the window is occupied
    void updateF(); //updates if the window is avaliable
    int getOccupiedTime(); //returns the occupied time
    void addWaitTime(int t); //adds the waittime
    int getWaitTime(); //returns the waittime
    void currentlyOccupied(); //occupied during current round
    void notCurrentlyOccupied(); //if not occupied during current round
    bool getCurrentlyOccupied(); //returns true or false


  private:
    int time;
    bool occupied;
    int occupiedTime;
    bool currently;

};
