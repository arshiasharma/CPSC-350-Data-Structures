#include "TreeNode.h"
#include <iostream>

using namespace std;

//default constructor
template <class T>
TreeNode<T>::TreeNode(){
  key = NULL;
  data = NULL;
  left = NULL;
  right = NULL;
}

//overload constructor
template <class T>
TreeNode<T>::TreeNode(int k, T *d){
  key = k;
  data = d;
  left = NULL;
  right = NULL;
}

//destructor
template <class T>
TreeNode<T>::~TreeNode(){
  left = NULL;
  right = NULL;
}
