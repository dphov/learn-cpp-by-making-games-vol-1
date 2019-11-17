//
// Created by Dmitry Petukhov on 05/10/2019.
//

#include <iostream>
using namespace std;

int main() {
  /*
   * myPointer
   * +---------+
   * | Address |
   * +---------+
   * |Var. Addr|
   * +---------+
   *
   *      OR
   *  myPointer             myVariable
   * +---------+           +---------+
   * | Address |    +----->| Address |
   * +---------+    |      +---------+
   * |    +---------+      |  Value  |
   * +---------+           +---------+
   */
  int x = 5;
  int *myIntPointer = nullptr;

  *myIntPointer = 10;
  myIntPointer = &x;
  *myIntPointer = 10;


  cout << "The value of x is: " << x << endl;
}