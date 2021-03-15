//header file for MirrorMode
#include <iostream>

using namespace std;

class MirrorMode{

  //member variables
  private:
    int neighborCount;
    int row;
    int column;
    char **board;
    char **board2;

  //methods
  public:
    MirrorMode();
    MirrorMode(int row, int column, char** board);
    ~MirrorMode();
    void simulation();
    void getBoard(int i, int j, int neighborCount);
    char** printBoard();
    char** fileBoard(string fileInput, int count);
    bool isEqual();
};
