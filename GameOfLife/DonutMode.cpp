//includes header files and fstream for writing to a file
#include "DonutMode.h"
#include <iostream>
#include <fstream>

using namespace std;

//default constructor
DonutMode::DonutMode(){
  neighborCount = 0;
  row = 0;
  column = 0;
}

//constructor
DonutMode::DonutMode(int r, int c, char** b){
  row = r;
  column  = c;

  board = b;
  board2 = new char *[row];
  	for(int i = 0; i < row ; i++){
  		   board2[i] = new char[column];
  	}
}

//destructor
DonutMode::~DonutMode(){
  delete board;
  delete board2;
}

//Making the new board, logic of the game
void DonutMode::simulation(){

  //for loop to iterate through the array
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){

      neighborCount = 0;

      //corner cells
      if((i == 0) && (j == 0)){
        if(board[i][j+1] == 'X'){
          neighborCount++;
        }if(board[i+1][j] == 'X'){
          neighborCount++;
        }if(board[i+1][j+1] == 'X'){
          neighborCount++;
        }if(board[i][j+(column-1)] == 'X'){
          neighborCount++;
        }if(board[i+1][j+(column-1)] == 'X'){
          neighborCount++;
        }if(board[i + (row-1)][j +(column - 1)] == 'X'){
          neighborCount++;
        }if(board[i + (row-1)][j] == 'X'){
          neighborCount++;
        }if(board[i + (row-1)][j+1] == 'X'){
          neighborCount++;
        }

        //adding the new cell to baord2
        getBoard(i, j, neighborCount);
        neighborCount = 0;

      //corner cell
      }else if((i == 0) && (j == (column - 1))){
        if(board[i][j-1] == 'X'){
          neighborCount++;
        }if(board[i+1][j-1] == 'X'){
          neighborCount++;
        }if(board[i+1][j] == 'X'){
          neighborCount++;
        }if(board[i + (row - 1)][j] == 'X'){
          neighborCount++;
        }if(board[i + (row - 1)][j-1] == 'X'){
          neighborCount++;
        }if(board[i + (row - 1)][0] == 'X'){
          neighborCount++;
        }if(board[i][0] == 'X'){
          neighborCount++;
        }if(board[i + 1][0] == 'X'){
          neighborCount++;
        }

        //adding the new cell to baord2
        getBoard(i, j, neighborCount);
        neighborCount = 0;

      //corner cell
      }else if((i == (row - 1)) && (j == (column - 1))){
          if(board[i][j-1] == 'X'){
            neighborCount++;
          }if(board[i-1][j] == 'X'){
            neighborCount++;
          }if(board[i-1][j-1] == 'X'){
            neighborCount++;
          }if(board[0][j] == 'X'){
            neighborCount++;
          }if(board[0][j-1] == 'X'){
            neighborCount++;
          }if(board[0][0] == 'X'){
            neighborCount++;
          }if(board[i][0] == 'X'){
            neighborCount++;
          }if(board[i-1][0] == 'X'){
            neighborCount++;
          }

          //adding the new cell to baord2
          getBoard(i, j, neighborCount);
          neighborCount = 0;

      //corner cell
      }else if((i == (row - 1)) && (j == 0)){
        if(board[i][j+1] == 'X'){
          neighborCount++;
        }if(board[i-1][j] == 'X'){
          neighborCount++;
        }if(board[i-1][j+1] == 'X'){
          neighborCount++;
        }if(board[0][0] == 'X'){
          neighborCount++;
        }if(board[0][j+1] == 'X'){
          neighborCount++;
        }if(board[0][j+(column - 1)] == 'X'){
          neighborCount++;
        }if(board[i][j + (column - 1)] == 'X'){
          neighborCount++;
        }if(board[i-1][j + (column - 1)] == 'X'){
          neighborCount++;
        }

        //adding the new cell to baord2
        getBoard(i, j, neighborCount);
        neighborCount = 0;

      //upper column
      }else if((!(i == 0) || (!(i == (row - 2)))) && (j == 0)){
        if(board[i-1][j] == 'X'){
          neighborCount++;
        }if(board[i-1][j+1] == 'X'){
          neighborCount++;
        }if(board[i][j+1] == 'X'){
          neighborCount++;
        }if(board[i+1][j+1] == 'X'){
          neighborCount++;
        }if(board[i+1][j] == 'X'){
          neighborCount++;
        }if(board[i][j+(column -1)] == 'X'){
          neighborCount++;
        }if(board[i-1][j+(column -1)] == 'X'){
          neighborCount++;
        }if(board[i+1][j+(column -1)] == 'X'){
          neighborCount++;
        }

        //adding the new cell to baord2
        getBoard(i, j, neighborCount);
        neighborCount = 0;

      //lower column
      }else if((0 < i <= (row - 2)) && (j == (column - 1))){
        if(board[i-1][j] == 'X'){
          neighborCount++;
        }if(board[i-1][j-1] == 'X'){
          neighborCount++;
        }if(board[i][j-1] == 'X'){
          neighborCount++;
        }if(board[i+1][j-1] == 'X'){
          neighborCount++;
        }if(board[i+1][j] == 'X'){
          neighborCount++;
        }if(board[i][0] == 'X'){
          neighborCount++;
        }if(board[i-1][0] == 'X'){
          neighborCount++;
        }if(board[i+1][0] == 'X'){
          neighborCount++;
        }

        //adding the new cell to baord2
        getBoard(i, j, neighborCount);
        neighborCount = 0;

      //upper row
      }else if((i == 0) && (0 < j <= (column - 2))){
        if(board[i][j-1] == 'X'){
          neighborCount++;
        }if(board[i+1][j-1] == 'X'){
          neighborCount++;
        }if(board[i+1][j] == 'X'){
          neighborCount++;
        }if(board[i+1][j+1] == 'X'){
          neighborCount++;
        }if(board[i][j+1] == 'X'){
          neighborCount++;
        }if(board[i+(row - 1)][j] == 'X'){
          neighborCount++;
        }if(board[i+(row - 1)][j-1] == 'X'){
          neighborCount++;
        }if(board[i+(row - 1)][j+1] == 'X'){
          neighborCount++;
        }

        //adding the new cell to baord2
        getBoard(i, j, neighborCount);
        neighborCount = 0;

      //lower row
      }else if((i == (row - 1)) && (0 < j <= (column - 2))){
        if(board[i][j-1] == 'X'){
          neighborCount++;
        }if(board[i-1][j-1] == 'X'){
          neighborCount++;
        }if(board[i-1][j] == 'X'){
          neighborCount++;
        }if(board[i-1][j+1] == 'X'){
          neighborCount++;
        }if(board[i][j+1] == 'X'){
          neighborCount++;
        }if(board[0][j] == 'X'){
          neighborCount++;
        }if(board[0][j-1] == 'X'){
          neighborCount++;
        }if(board[0][j+1] == 'X'){
          neighborCount++;
        }

        //adding the new cell to baord2
        getBoard(i, j, neighborCount);
        neighborCount = 0;

      //cells in the middle
      }else{
        if(board[i-1][j-1] == 'X'){
          neighborCount++;
        }if(board[i-1][j] == 'X'){
          neighborCount++;
        }if(board[i-1][j+1] == 'X'){
          neighborCount++;
        }if(board[i][j-1] == 'X'){
          neighborCount++;
        }if(board[i][j+1] == 'X'){
          neighborCount++;
        }if(board[i+1][j-1] == 'X'){
          neighborCount++;
        }if(board[i+1][j] == 'X'){
          neighborCount++;
        }if(board[i+1][j+1] == 'X'){
          neighborCount++;
        }

        //adding the new cell to baord2
        getBoard(i, j, neighborCount);
        neighborCount = 0;
      }
    }
  }
}

//Method for adding the new cell to board2
void DonutMode::getBoard(int i, int j, int count){

    if(count == 3){
      board2[i][j] = 'X';

    }else if(count == 4){
      board2[i][j] = '-';

    }else if(count == 1 || count == 0){
      board2[i][j] = '-';

    }else if(count == 2){
      board2[i][j] = board[i][j];
    }else{
      board2[i][j] = '-';
    }
}

//Method for printing board to the terminal
char** DonutMode::printBoard(){

  if(board == board2){
    cout << "Board is the same" << endl;

  }
  for(int i = 0; i < row; i++){
    cout << endl;
    for(int j = 0; j < column; j++){
     cout << board2[i][j] << "\t";
    }
  }
  cout << endl;
  return board2;
}

//Printing the board to a file
char** DonutMode::fileBoard(string file, int count){

  //opening new file stream
  ofstream answerFile;

  answerFile.open(file, fstream::app);

  answerFile << "Board " << count << endl;

  for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j++){
       answerFile << board2[i][j] << "\t";
      }
      answerFile << "\n";
    }
    answerFile << endl;
    answerFile.close();
    return board2;
}

//Method for checking if the boards are equal - check README
bool DonutMode::isEqual(){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
        if (board[i][j] != board2[i][j]){
            return false;
        }
      }
    }
  return true;
}
