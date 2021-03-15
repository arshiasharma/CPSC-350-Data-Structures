#include <iostream>

class GenQueue{
  public:
    GenQueue(); //default constructor
    GenQueue(int maxSize); //overload constructor
    ~GenQueue();

    //core functions
    void insert(char d);
    char remove();

    //aux functions
    char peek();
    bool isFull();
    bool isEmpty();
    int getSize();

    //var
    int front; //aka front
    int rear; //aka tail
    int size;
    int numElements;

    char *myQueue; //array
};
