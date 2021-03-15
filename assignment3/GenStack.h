#include <iostream>

using namespace std;

template <class T> //The templates - README for template reference

class GenStack{
  public:
    GenStack(); //constructor
    GenStack(int maxSize); //overload constructor
    ~GenStack(); //destructor

    void newStack();
    void push(T d);
    T pop();
    T peek(); //AKA top()

    bool isFull();
    bool isEmpty();

    int size;
    int top;

    T *myArray; //declaring a pointer (memory address), pointing to the first element in an array
};
