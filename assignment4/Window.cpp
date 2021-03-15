#include "Window.h"
#include <iostream>

using namespace std;

//default constructor
Window::Window(){
  time = 0;
  occupiedTime = 0;
}

//overload constructor
Window::Window(int t){
  time = t;
  occupied = false;
  currently = false;
}

//destructor
Window::~Window(){
}

//adds the window waittime
void Window::addWaitTime(int t){
  time = t;
}

//returns window waittime
int Window::getWaitTime(){
  return time;
}

//trues boolean expression if the window is occupied
bool Window::isOccupied(){
  return occupied;
}

//if the window is free, it'll update the window to be free
void Window::updateT(){
  occupied = true;
}

//if the window is occupied, it'll update the window to be occupied(false)
void Window::updateF(){
  occupied = false;
}

//adds the time which the window is occupied for reference
void Window::addOccupiedTime(int t){
  occupiedTime += t;
}

//returns the occupied time
int Window::getOccupiedTime(){
  return occupiedTime;
}

void Window::currentlyOccupied(){
  currently = true;
}

void Window::notCurrentlyOccupied(){
  currently = false;
}

bool Window::getCurrentlyOccupied(){
  return currently;
}
