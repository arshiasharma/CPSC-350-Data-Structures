#include <iostream>

using namespace std;

class Simulation{
  public:
    Simulation();
    ~Simulation();

    void simulation(string file);
    void bubbleSort(double myArray[]);
    void insertSort(double myArray[]);
    void selectionSort(double myArray[], int n);
    void quickSort(double myArray[], int l, int g);
    int divide(double myArray[], int l, int g);
    void mergeSort(double myArray[], int s, int e);
    void mergeS(double myArray[], int s, int m, int e);

  private:
    double *bubbleArr;
    double *insertArr;
    double *quickArr;
    double *selectionArr;
    double *mergeArr;

    int n; //number of elements in the file
};
