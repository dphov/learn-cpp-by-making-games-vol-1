//
// Created by Dmitry Petukhov on 05/10/2019.
//

#include <iostream>
using namespace std;

int main()
{
  /*
   * Variable
   * +---------+
   * | Address | 1000
   * +---------+
   * | Value   | 5
   * +---------+
   */

  int x = 5;

  cout << "The address of x is: " << &x << endl;
}