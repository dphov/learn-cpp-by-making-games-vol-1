//
// Created by Dmitry Petukhov on 05/10/2019.
//
#include <iostream>
using namespace std;

int main()
{
  int x = 5;

  int & intRef = x;

  intRef = 10;

  cout << "x is: " << x << endl;

  return 0;
}