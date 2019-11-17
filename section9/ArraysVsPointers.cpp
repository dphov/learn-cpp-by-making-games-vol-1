//
// Created by Dmitry Petukhov on 13/10/2019.
//

#include <iostream>
using namespace std;

int main ()
{
  /*
   *              0   1   2   3   4   ...  n-1
   *            +---+---+---+---+---+     +---+
   * array name |   |   |   |   |   | ... |   |
   *            +---+---+---+---+---+     +---+
   *
   */
  int array[5] = {2, 4, 6, 8, 10};
//
//  int * ptr = nullptr;
//
//  ptr = array;

  // the equivalent to this is

//  ptr = &array[0];
//
//
//  cout << "The value pointed to by ptr is: " << *ptr << endl;
//
//  cout << "The address of the element zero is: " << array << endl;
//
//  cout << "The address of the element 1 is: " << &array[1] << endl;
//
//  ptr[1] = 5;
//
//  cout << "array[1] is: " << array[1] << endl;


 int sum = 0;

 int * ptr = &array[0];

// for (int i = 0; i < 5; i++ )
//   {
//     sum += ptr[i];
//   }

  for (int i = 0; i < 5; i++ )
    {
      sum += *ptr;
      ptr++;
    }

 cout << "The sum is :" << sum << endl;

  return 0;
}