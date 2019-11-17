
#include <iostream>
using namespace std;

//void Swap(int & x, int & y);

void Swap(int * x, int * y);

int main()
{
  // Problem 1: Write a function that will swap the 2 values of 2 integers

//  int x = 5;
//  int y = 15;
//
//  Swap(x, y);
//
//  cout << "The value of x is: " << x << endl;
//  cout << "The value of y is: " << y << endl;

  // Problem: Write a function called swap that takes in two integers by pointer and swaps their values.
  int x = 5;
  int y = 15;
  int * ptrX = &x;
  int * ptrY = &y;
  Swap(ptrX, ptrY);

  cout << "The value of x is: " << x << endl;
  cout << "The value of y is: " << y << endl;

  return 0;
}

void Swap(int * x, int * y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
//void Swap(int & x, int & y)
//{
//  int temp = x;
//  x = y;
//  y = temp;
//}