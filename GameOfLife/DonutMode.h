//header file for DonutMode
#include <iostream>

using namespace std;

class DonutMode{

  //member variables
  private:
    int neighborCount;
    int row;
    int column;
    char **board;
    char **board2;

  //methods
  public:
    DonutMode();
    DonutMode(int row, int column, char** board);
    ~DonutMode();
    void simulation();
    void getBoard(int i, int j, int neighborCount);
    char** printBoard();
    char** fileBoard(string fileInput, int count);
    bool isEqual();
};
