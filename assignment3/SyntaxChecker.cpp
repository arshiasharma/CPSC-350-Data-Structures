#include "SyntaxChecker.h"
#include <fstream> //reading in and out of files
#include <iostream>

//default constructor
SyntaxChecker::SyntaxChecker(){
  myStack = GenStack<char>();
  curlyBracket = '{';
  para = '(';
  bracket = '[';
}

//overload constructor
SyntaxChecker::SyntaxChecker(int s){
  myStack = GenStack<char>(s);
  curlyBracket = '{';
  para = '(';
  bracket = '[';
}

//destructor
SyntaxChecker::~SyntaxChecker(){
  myStack.~GenStack();
}

//logic of the program -> finds the delimiter issues
bool SyntaxChecker::simulation(string file){
  string tempQ = "'";
  char singleQuote = tempQ.at(0); //README - having a ' as a char

  //keeping track of the line count
  int count = 0;
  string line;

  //following four variables keep track of comments/strings that Java and C++ uses
  //keeps track of /
  int comment = 0;

  //keeps track of *
  int star = 0;

  //variable to keep track of strings "..." that wont affect the code
  int quote = 0;

  //variable to keep track of JavaDoc comments (/** .. */)
  int javaDoc = 0;

  //reading into a file
  ifstream infile(file);
  while(getline(infile, line)){
       count++;

       //for loop to look at each character in the line
      for(char i : line){

        //accounting for comments
        if(i == '/'){
          comment++;
        }if(i == '*'){
          star++;

        //the basic one line comments (//)
        }if(comment == 2 && star == 0){
          comment = 0;

        //begining of regular C++/Java block comments
        }if(comment == 1 && star == 1){
          continue;
        //end of C++/Java comments
        }if(comment == 2 && star == 2){
          comment = 0;
          star = 0;
          continue;

        //JavaDoc comments (/** ... */)
        }if(comment == 1 && star == 2){
          continue;

        //doesnt keep track of the * on each line for the JavaDoc block comments
        }if(comment == 2){
          comment = 0;
          star = 0;
          continue;
        }

        //accounting for strings where having delimiters wont affect the code
        if(i == '"' || i == singleQuote){
          quote++;
        }if(quote == 1){
          continue;
        }if(quote == 2){
          quote = 0;
          continue;
        }

        //if it's an open delimiter, add the stack
        if((i == '(') || (i == '{') || (i == '[')){
          if(myStack.isFull()){
            myStack.newStack();
          }
          myStack.push(i);

        //if it's a closed delimiter, check for errors
        }else if((i == ')') || (i == '}') || (i == ']')){

          //if stack empty, then there's a missing delimiter or an extra one
          if(myStack.isEmpty()){
            char expected;
            if(i == ')'){
              expected = para;
            }if(i == '}'){
              expected = curlyBracket;
            }if(i == ']'){
              expected = bracket;
            }
            cout << "Line " << count << ": Expected " << expected << " but not found" << endl;
            return false;

          //checking when the closed delimiter does not match the open one on the stack
          }else if(i == ')'){
            char curr = myStack.pop();
            if(curr == curlyBracket || curr == bracket){
              cout << "Line " << count << " Expected: " << para << " but found " << curr << endl;
              return false;
            }

          //checking when the closed delimiter does not match the open one on the stack
          }else if(i == '}'){
            char curr = myStack.pop();
            if(curr == para || curr == bracket){
              cout << "Line " << count << ": Expected " << curlyBracket << " but found " << curr << endl;
              return false;
            }

          //checking when the closed delimiter does not match the open one on the stack
          }else if(i == ']'){
            char curr = myStack.pop();
            if(curr == para || curr == curlyBracket){
              cout << "Line " << count << ": Expected " << bracket << " but found " << curr << endl;
              return false;
            }
          }
        }
      }
    }
    //if the stack is not empty at the end of the file
    if(myStack.isEmpty() == false){
      cout << "Stack is not empty, there's still " << myStack.peek() << " left at the end of the file" << endl;
      return false;
    //if the stack is empty at the end of the file
    }if(myStack.isEmpty()){
      cout << "Your file is correct" << endl;
      return true;
    }
  }
