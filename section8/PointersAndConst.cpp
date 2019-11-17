#include <iostream>

using namespace std;


int main()
{

  int x = 5;

  // constant pointer 1: can change address but can't change the value;
  // from right to left: pointer to integer constant

  const int * xPtr = &x;

  int y = 15;

  xPtr = &y;
  cout << "xPtr value is: " << *xPtr << endl ;

  // constant pointer 2: can't change address but can change the value;
  // from right to left: constant to pointer that has type integer, constant pointer to integer
  // references are basically constant pointers;
  int * const yPtr = &y;

  *yPtr = 19;

  // Can't change where it points to or change it's value
  const int & xRef = x;

  cout << "xRef address is: " << &xRef << endl ;


  // Pointer equivalent
  const int * const xPtr2 = &x;

  return 0;
}