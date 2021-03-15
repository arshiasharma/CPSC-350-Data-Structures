#include "GenQueue.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv){

  GenQueue q(10);

  q.insert('2');
  q.insert('1');
  q.insert('3');
  q.insert('5');

  cout << "peek: " << q.peek() << endl;
  cout << "remove: " << q.remove() << endl;

  q.insert('h');
  q.insert('i');

  while(!(q.isEmpty())){
    cout << "remove: " << q.remove() << endl;
  }
  return 0;
}
