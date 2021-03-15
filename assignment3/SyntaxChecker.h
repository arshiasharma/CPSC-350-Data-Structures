#include <iostream>
#include "GenStack.cpp"

using namespace std;

class SyntaxChecker{
  public:
    SyntaxChecker(); //default constructor
    SyntaxChecker(int s); //constructor
    ~SyntaxChecker(); //destructor

    bool simulation(string file);

    GenStack<char> myStack;

    char curlyBracket;
    char para;
    char bracket;
};
