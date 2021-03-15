//header files
#include "GameOfLife.h"
#include "ClassicMode.h"
#include "DonutMode.h"
#include "MirrorMode.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (){

  string filePick;
  string boardPick;
  string pause;
  int config  = 0;
  bool loop = true;
  bool mainLoop = true;
  int row;
  int column;
  float popDensity;
  string file;
  string fileInput;
  char** board;
  char** board2;
  char answer;
  string slow;
  int check = 0;

  //Loop for making a random generation or import from a file
  while(loop){
    cout << "Do you wish to start with a random configuration, or specify a flatfile configuration" << endl;
    cout << "Enter 1 for random or 2 for flatfile: ";
    cin >> config;

    //random file configuration
    if(config == 1){
      cout << "Please enter the dimenisions for the world" << endl;

      cout << "Enter rows: ";
      cin >> row;
      cout << "Enter columns: ";
      cin >> column;

      cout << "Enter a decimal for the population density (0 - 1): ";
      cin >> popDensity;

      if(0 < popDensity <= 1 ){
        cout << "Not a valid number, please try again: ";
        cin >> popDensity;
      }

      //makes Board 0, uses a pointer, makes an instance of GameOfLife
      GameOfLife* g = new GameOfLife(row, column, popDensity);
      board = g->randGen();

      loop = false;

    //file generation
    }else if(config == 2){

      string temp = "";
      string line = "";

      cout << "Enter the file: ";
      cin >> file;

      //opens a file - learned from Assignment 1
      ifstream infile(file);

      if(infile.fail()){
        cout << "Fail doesnt exist, please try again with text files in the code" << endl;
        cout << endl;
        continue;
      }

      while(getline(infile, line)){
        temp += line;
      }

      //the char is converted to the ASCII code, subtracted by 48 to make up for it - README
      row = int(temp[0]) - 48;
      column = int(temp[1]) - 48;

      //makes Board 0, uses a pointer, makes an instance of GameOfLife
      GameOfLife* g = new GameOfLife(row, column, temp);
      board = g->fileGen();

      loop = false;

    //else case, repromtps user
    }else{
      cout << "Please enter 1 or 2: " << endl;
      loop = true;
      continue;
    }
  }

  //loop of the simulation with the different modes
  while(mainLoop){

    //Lets user choose what game mode
    //If not a valid option, it'll reprompt the user at line 540
    cout << "Pick a board to begin to play: classic (c), donut (d), mirror (m): ";
    cin >> boardPick;

    //If the data should be in a file instead of the terminal
    cout << "Would you like the boards mapped to a file (y/n): ";
    cin >> filePick;

    //Enter the output file
    if(filePick == "y"){
      cout << "Enter output file name: ";
      cin >> fileInput;

    //Ask user if they want automatic pauses or use keys to see each board
    }if(filePick == "n"){
      cout << "Would you like automatic pauses between boards or press the key 'y'?" << endl;
      cout << "Press 'y' for automatic pauses and 'n' for using the key: ";
      cin >> pause;
    }

    int count = 0;

    //ClassicMode loop
    if((boardPick == "c") || (boardPick == "classic")){

        //outputing boards to a file
        if(filePick == "y"){

            //Opening a text file
            ofstream output;

            //will override what is in the file currently; will keep all the data that will be written until the program is executed again
            output.open (fileInput);
            output << "Board 0" << endl;

            //iterating through the 2D array
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                 output << board[i][j] << "\t";
                }
                output << "\n";
              }
              output << endl;
              output.close();
              count++;

            //high number to ensure enough loops
            while(count < 100){

              //making an object of class ClassicMode
              ClassicMode* c = new ClassicMode(row, column, board);

              //Entering simulation method
              c->simulation();

              //method to print data to file
              board = c->fileBoard(fileInput, count);
              count++;

              //method to check if the boards are the same, checks it for 5 times
              if(c->isEqual()){
                check++;

                //breaks out of the loop
                if(check == 5){
                  cout << "Board stablizes or is empty, program ends" << endl;
                  cout << "The output in " << fileInput << endl;
                  break;
                }
              }else{
                continue;
              }
            }

      //prints data to the terminal
      }else if (filePick == "n"){

          //automatic pauses for each board
          if(pause == "y"){
            while(count < 1000){

              //making an object of class ClassicMode
              ClassicMode* c = new ClassicMode(row, column, board);

              count++;

              //Entering simulation method
              c->simulation();

              cout << endl;
              cout << "Board number: " << count << endl;
              cout << endl;

              //prints board to the terminal
              board = c->printBoard();



              //for loop to slow down the program, automatic pauses
              for(int i = 0; i < 1000; i++){
                for(int i = 0; i < 70000; i++){
                  slow+=i;
                }
                slow += i;
              }

              //if the boards are equal 5 times in a row, the program ends
              if(c->isEqual()){
                check++;

                if(check == 5){
                  cout << "Board stablizes or is empty, program ends" << endl;
                  break;
                }
              }else{
                continue;
              }
            }

          //Loop where the user presses the y key to see each board
          }else if(pause == "n"){

            //Ensuring enough loops
            while(count < 100){

              //making an object of class ClassicMode
              ClassicMode* c = new ClassicMode(row, column, board);

              count++;

              //Entering simulation method

              c->simulation();

              cout << endl;
              cout << "Board number: " << count << endl;
              cout << endl;

              //prints board to the terminal
              board = c->printBoard();

              cout << "Press 'y' to continue: ";
              cin >> answer;

              //if the boards are equal 5 times in a row, the program ends
              if(c->isEqual()){
                check++;

                if(check == 5){
                  cout << "Board stablizes or is empty, program ends" << endl;
                  cout << "Press 'y' to quit: ";
                  cin >> answer;
                  if(answer == 'y'){
                    break;
                  }
              }else{
                continue;
              }
            }
          }
        }
      }

      mainLoop = false;

    //Donut Mode loop
    }else if((boardPick == "d") || (boardPick == "donut")){

      //outputing boards to a file
      if(filePick == "y"){

      ofstream output;

      //will override what is in the file currently; will keep all the data that will be written until the program is executed again
      output.open (fileInput);
      output << "Board 0" << endl;

      //iterating through the 2D array
      for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            output << board[i][j] << "\t";
          }
          output << "\n";
        }
        output << endl;
        output.close();
        count++;

        //high number to ensure enough loops
        while(count < 100){

          //making an object of class ClassicMode
          DonutMode* d = new DonutMode(row, column, board);

          //Entering simulation method
          d->simulation();

          //method to print data to file
          board = d->fileBoard(fileInput, count);
          count++;

          //if the boards are equal 5 times in a row, the program ends
          if(d->isEqual()){
            check++;

            if(check == 5){
              cout << "Board stablizes or is empty, program ends" << endl;
              cout << "The output in " << fileInput << endl;
              break;
            }
          }else{
            continue;
          }
        }

      //Loop that prints the terminal with automatic pauses
      }else if (filePick == "n"){
        if(pause == "y"){

          //Ensures enough loops
          while(count < 1000){

            //making an object of class DonutcMode
            DonutMode* d = new DonutMode(row, column, board);

            count++;

            //Entering simulation method
            d->simulation();

            cout << endl;
            cout << "Board number: " << count << endl;
            cout << endl;

            //prints board to the terminal
            board = d->printBoard();

            //for loop to slow down the program, automatic pauses
            for(int i = 0; i < 1000; i++){
              for(int i = 0; i < 70000; i++){
                slow+=i;
              }
              slow += i;
            }

            //if the boards are equal 5 times in a row, the program ends
            if(d->isEqual()){
              check++;

              if(check == 5){
                cout << "Board stablizes or is empty, program ends" << endl;
                break;
              }
            }else{
              continue;
            }
          }

      //Loop where the user presses the y key to see each board
      }else if(pause == "n"){

        //Ensures enough loops
        while(count < 100){

          //making an object of class DonutMode
          DonutMode* d = new DonutMode(row, column, board);

          count++;

          //Entering simulation method
          d->simulation();

          cout << endl;
          cout << "Board number: " << count << endl;
          cout << endl;

          //prints board to the terminal
          board = d->printBoard();

          cout << "Press 'y' to continue: ";
          cin >> answer;

          //if the boards are equal 5 times in a row, the program ends
          if(d->isEqual()){
            check++;

            if(check == 5){
              cout << "Board stablizes or is empty, program ends" << endl;
              cout << "Press 'y' to quit: ";
              cin >> answer;
              if(answer == 'y'){
                break;
              }
            }else{
              continue;
          }
        }
      }
    }
  }

  mainLoop = false;

  //Mirror Mode loop
  }else if((boardPick == "m") || (boardPick == "mirror")){

    //outputing boards to a file
    if(filePick == "y"){
        ofstream output;

        //will override what is in the file currently; will keep all the data that will be written until the program is executed again
        output.open (fileInput);
        output << "Board 0" << endl;

        //Makes Board 0
        for(int i = 0; i < row; i++){
          for(int j = 0; j < column; j++){
              output << board[i][j] << "\t";
          }
          output << "\n";
        }
        output << endl;
        output.close();
        count++;

        //high number to ensure enough loops
        while(count < 100){

          //making an object of class DonutMode
          MirrorMode* m = new MirrorMode(row, column, board);

          //Entering simulation method
          m->simulation();

          //method to print data to file
          board = m->fileBoard(fileInput, count);
          count++;

          //if the boards are equal 5 times in a row, the program ends
          if(m->isEqual()){
            check++;

            if(check == 5){
              cout << "Board stablizes or is empty, program ends" << endl;
              cout << "The output in " << fileInput << endl;
              break;
            }
          }else{
            continue;
          }
        }

      //Loop that prints the terminal with automatic pauses
      }else if (filePick == "n"){
        if(pause == "y"){
          while(count < 1000){

            //making an object of class MirrorMode
            MirrorMode* m = new MirrorMode(row, column, board);

            count++;

            //Entering simulation method
            m->simulation();

            cout << endl;
            cout << "Board number: " << count << endl;
            cout << endl;

            //prints board to the terminal
            board = m->printBoard();

            //for loop to slow down the program, automatic pauses
            for(int i = 0; i < 1000; i++){
              for(int i = 0; i < 70000; i++){
                slow+=i;
              }
              slow += i;
            }

            //if the boards are equal 5 times in a row, the program ends
            if(m->isEqual()){
              check++;

              if(check == 5){
                cout << "Board stablizes or is empty, program ends" << endl;
                break;
              }
            }else{
              continue;
            }
          }
        }else if(pause == "n"){

          //Ensures enough loops
          while(count < 100){

            //making an object of class MirrorMode
            MirrorMode* m = new MirrorMode(row, column, board);

            count++;

            //Entering simulation method
            m->simulation();

            //prints board to the terminal

            cout << endl;
            cout << "Board number: " << count << endl;
            cout << endl;

            board = m->printBoard();

            cout << "Press 'y' to continue: ";
            cin >> answer;

            //if the boards are equal 5 times in a row, the program ends
            if(m->isEqual()){
              check++;

              if(check == 5){
                cout << "Board stablizes or is empty, program ends" << endl;
                cout << "Press 'y' to quit: ";
                cin >> answer;
                if(answer == 'y'){
                  break;
                }
              }
            }else{
              continue;
            }
          }
        }
      }
      mainLoop = false;

      //else loop to catch is the user inputs the wrong mode
      }else{
        cout << "Did not enter the right mode, please try again" << endl;
        mainLoop = true;
      }
    }
  }
