#include "BST.h"
#include <iostream>
#include <fstream>

using namespace std;

//default constructor
template <class T>
BST<T>::BST(){
  root = NULL; //empty tree
}

//destructor
template <class T>
BST<T>::~BST(){
  //character buildin
  delete root;
}

//recPrint - prints out info of node
template <class T>
void BST<T>::recPrint(TreeNode<T>* node){

  if(node == NULL){
    return;
  }
  //inorder traversal
  recPrint(node->left);
  node->data->getInfo();
  cout << endl;
  recPrint(node->right);
}


//prints contents of the tree
template <class T>
void BST<T>::printTree(){
  recPrint(root);
}

//get the node of the highest key
template <class T>
TreeNode<T>* BST<T>::getMax(){
  TreeNode<T> *current = root;

  if(root == NULL){ //empty tree
    return NULL;
  }

  while(current->right != NULL){
    current = current->right;
  }
  return current;
}

//getting the node of the lowest key value
template <class T>
TreeNode<T>* BST<T>::getMin(){
  //oppostion of getMin
  TreeNode<T> *current = root;

  if(root == NULL){ //empty tree
    return NULL;
  }

  while(current->left != NULL){
    current = current->left;
  }
  return current;
}

//inserting into the tree
template <class T>
void BST<T>::insert(int k, T *value){
  TreeNode<T> *node = new TreeNode<T>(k, value);

  if(root == NULL){
    root = node;
  }

  else{
    TreeNode<T> *current = root;
    TreeNode<T> *parent = NULL;

    while(true){
      parent = current;

      if(k < current->key){
        current = current->left;

        if(current == NULL){
          //we found the insertion point
          parent->left = node;
          break;
        }


      }else{
        current = current->right;

        if(current == NULL){
          //we found the insertion point
          parent->right = node;
          break;
        }
      }
    }
  }
}

//searching for the node with the int value
template <class T>
T* BST<T>::search(int value){
  if(root == NULL){
    cout << "empty tree" << endl;
  }

  else{
    //tree is not empty, lets find it
    TreeNode<T> *current = root;

    while(current->key != value){
      if(value < current->key){
        current = current->left;
      }else{
        current = current->right;
      }
      if(current == NULL){ //value doesnt exist
        cout << endl;
        return NULL;
      }
    }
    return current->data;
  }
}

//deleting a node given the key
template <class T>
bool BST<T>::deleteNode(int k){
  if(root == NULL){
    cout << "empty tree" << endl;
    return false;
  }

  TreeNode<T> *current = root;
  TreeNode<T> *parent = root;
  bool isLeft = true;

  //if we make it here, the tree isnt empty so we find node

  while(current->key != k){
    parent = current;
    if(k < current->key){
      isLeft = true;
      current = current->left;
    }else{
      isLeft = false;
      current = current->right;
    }
    if(current == NULL){ //value doesnt exist
      cout << "value doesnt exist" << endl;
      return false;
    }
  }

  //no children (leaf)

  if(current->left == NULL && current->right == NULL){
    if(current == root){
      root = NULL;
    }else if (isLeft){
      parent->left = NULL;
    }else{
      parent->right = NULL;
    }
  }

  //node to be deleted has one child, we need to know if child is left or right
  else if(current->right == NULL){ //doesnt have right, should be left child
    //need to check if its a root
    if(current == root){
      root = current->left;
    }else if(isLeft){
      parent->left = current->left;
    }else{ //right child
      parent->right = current->left;
    }
  }

  else if(current->left == NULL){ //doesnt have left, should be right child
    //need to check if its a root
    if(current == root){
      root = current->right;
    }else if(isLeft){
      parent->left = current->right;
    }else{ //right child
      parent->right = current->right;
    }
  }

  else{
    //node to be deleted has 2 children so rip
    TreeNode<T> *successor = getSuccessor(current);

    if(current == root){
      root = successor;
    }else if(isLeft){
      parent->left = successor;
    }else{
      parent->right = successor;
    }
    successor->left = current->left;
  }
  return true;
}

//getting the successor of the node
template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){ //d is the node to be deleted
  TreeNode<T> *current = d->right;
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;

  while(current != NULL){
    //traverse tree until we find successor
    sp = successor;
    successor = current;
    current = current->left;
  }

  //by this point, all of our pointers such be in the right spot
  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

//serializing to the file
template<class T>
void BST<T>::serializationMain(TreeNode<T>* node, string f){
  ofstream output;
  output.open(f, fstream::app);

  bool loop = true;

  if(node == NULL){
    return;
  }

  output << node->data->getFile() << endl;

  serializationMain(node->left, f);

  serializationMain(node->right, f);


}

//serializing the root node
template <class T>
void BST<T>::serialization(string f){

  ofstream output;
  output.open(f);

  if(root == NULL){
    cout << "Tree empty, try again" << endl;
  }

  else{
    output << root->data->getFile() << endl;
  }
  if(root->left != NULL){
    serializationMain(root->left, f);
  }
  if(root->right != NULL){
    serializationMain(root->right, f);
  }
}

//is the tree empty
template <class T>
bool BST<T>::isEmpty(){
  if(root == NULL){
    return true;
  }else{
    return false;
  }
}
