#include <iostream>
using namespace std;


void Func(const int array[], int length);


int main()
{
  /*
  *              0   1   2   3   4   ...  n-1
  *            +---+---+---+---+---+     +---+
  * array name |   |   |   |   |   | ... |   |
  *            +---+---+---+---+---+     +---+
  *
  */

  int array[] = {1,3,5,7,9};

  Func(array, 5);

  for (int i = 0; i < 5; i++)
    {
      cout << "array[" << i << "]: " << array[i] << endl;
    }

  return 0;
}

void Func(int array[], int length)
{
  for (int i = 0; i < length; i++)
    {
      array[i]++;
    }
}