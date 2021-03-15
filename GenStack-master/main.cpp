#include "GenStack.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv){
  GenStack myStack(10);

  myStack.push('3');
  myStack.push('1');
  myStack.push('2');

  cout << "popping: " << myStack.pop() << endl;
  cout << "peek-a-boo: " << myStack.peek() << endl;

  myStack.push('5');
  cout << "peek: " << myStack.peek() << endl;

  while(!myStack.isEmpty()){
    cout << "pop: " << myStack.pop() << endl;
  }

  cout << "is stack empty? " << myStack.isEmpty() << endl;
  return 0;
}
