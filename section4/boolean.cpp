#include <iostream>
using namespace std;

int main()
{
  bool myBoolean = false;
  // >, <, >=, <=, ==
//
//  float pi = 3.14;
//  float pi2 = 3.1415;
//
//  bool result = ( pi != pi2);

//  bool result = true || false;

  bool A = true;
  bool B = false;

  int x = 10;
  int y = 0;

//  bool result = (A && B) || (x > y); // true
//  bool result = (!A || B) &&  (x <= y); // false
  bool result = !((A == B) && (x == y)); // true
  cout << "The value of result is: " << result << endl;
  return 0;
}
