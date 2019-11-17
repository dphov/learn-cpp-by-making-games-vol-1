//
// Created by Dmitry Petukhov on 12/10/2019.
//

#include <iostream>
using namespace std;

int main ()
{
  const int MAX = 5;
  int intArray[MAX] = {2, 4, 6, 8, 10};

  int sum = 0;

  for (int i = 0; i < MAX; i++)
  {
    sum += intArray[i];
  }

  cout << "The sum is: " << sum << endl;

  /*
   *              0   1   2   3   4   ...  n-1
   *            +---+---+---+---+---+     +---+
   * array name |   |   |   |   |   | ... |   |
   *            +---+---+---+---+---+     +---+
   *
   */

  return 0;
}