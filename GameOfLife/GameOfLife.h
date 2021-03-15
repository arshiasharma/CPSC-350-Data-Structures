//header file for GameOfLife - logic before the game begins, prompting the user
#include <iostream>

using namespace std;

class GameOfLife{

  //member variables
  private:
    int row;
    int column;
    char **board;
    char **board2;
    float popDensity;
    string temp;

  //methods
  public:
    GameOfLife();
    GameOfLife(int row, int column, float popDensity);
    GameOfLife(int row, int column, string temp);
    ~GameOfLife();

    //methods for prompting the user
    char** randGen();
    char** fileGen();
    int getRow();
    int getColumn();



};
