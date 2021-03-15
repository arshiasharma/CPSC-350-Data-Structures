//header file for ClassicMode
#include <iostream>

using namespace std;

class ClassicMode{

  //member variables
  private:
    int neighborCount;
    int row;
    int column;
    char **board;
    char **board2;


  //methods
  public:
    ClassicMode();
    ClassicMode(int row, int column, char** board);
    ~ClassicMode();
    void simulation();
    void getBoard(int i, int j, int neighborCount);
    char** printBoard();
    char** fileBoard(string fileInput, int count);
    bool isEqual();

};
