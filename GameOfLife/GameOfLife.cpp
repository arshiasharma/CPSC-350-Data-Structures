//includes header files and fstream for writing to a file
#include "GameOfLife.h"
#include <iostream>
#include <fstream>

using namespace std;

//default constructor
GameOfLife::GameOfLife(){
  row = 0;
  column  = 0;
  popDensity = 0;
  temp = "";
}

//constructor for random generation
GameOfLife::GameOfLife(int r, int c, float p){
  row = r;
  column  = c;
  popDensity = p;
}

//constructor for file input
GameOfLife::GameOfLife(int r, int c, string t){
  row = r;
  column  = c;
  temp = t;
}

//destructor
GameOfLife::~GameOfLife(){
  delete board;
}

//random generation of a board
char** GameOfLife::randGen(){
  srand(time(0)); //to make the rand actually random - README

  //making the 2D array
  board = new char *[row];
		for(int i = 0; i < row ; i++){
		    board[i] = new char[column];
		}

  //making the 2D array
  board2 = new char *[row];
  	for(int i = 0; i < row ; i++){
  		   board2[i] = new char[column];
  	}

  int mult = row * column;
  int cells = mult * popDensity;
  int i = 0;

  //randomly adding occupied cells to the board
  while(i < cells){
      int a =  rand() % row;
      int b =  rand() % column;

      if(board[a][b] == 'X'){
        continue;
      }else{
        board[a][b] = 'X';
        board2[a][b] = 'X';
        i++;
      }
    }

    //outputting the board to the user
    cout << "Board 0" << endl;
    for(int i = 0; i < row; i++){
      cout << endl;
      for(int j = 0; j < column; j++){
        if(!(board[i][j] == 'X')){
          board[i][j] = '-'; //adding the unoccupied cells
          board2[i][j] = '-';
        }
        cout << board[i][j] << "\t";
      }
    }
    cout << endl;
    return board;
  }

  //method for the genration of an inputted file
  char** GameOfLife::fileGen(){

    //making the new board
    board = new char *[row];
  		for(int i = 0; i < row ; i++){
  		    board[i] = new char[column];
  		}

    //making board2
    board2 = new char *[row];
    	for(int i = 0; i < row ; i++){
    		   board2[i] = new char[column];
    	}

      //starts at two since first two lines at the number of rows and columns
      int count = 2;

      //outputs the board to the terminal for user to check 
      cout << "Board 0" << endl;
        for(int i = 0; i < row; i++){
          cout << endl;
          for(int j = 0; j < column; j++){
              board[i][j] = char(temp[count]);
              board2[i][j] = char(temp[count]);
              count++;

              cout << board[i][j] << "\t";
            }
        }
        cout << endl;
        return board;
    }
