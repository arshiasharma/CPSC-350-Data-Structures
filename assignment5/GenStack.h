#include <iostream>

using namespace std;

template <class T> //The templates - README for template reference

class GenStack{
  public:
    GenStack(); //default constructor
    GenStack(int maxSize); //overload constructor
    ~GenStack(); //destructor

    void newStack(); //if the stack is full, a new stack is created with double to orginal size
    void push(T d); //pushes element T on top of the stack
    void push2 (T* d); //pushes element T* on top of the stack
    T pop(); //removing top element from the top of the stack
    T* pop2(); //removing top element pointer from the top of the stack
    T peek(); //returns but doesnt remove first element

    bool isFull(); //true if full
    bool isEmpty(); //true if empty

    //member variables
    int size;
    int top;
    T *myArray; //declaring a pointer (memory address), pointing to the first element in an array
};
