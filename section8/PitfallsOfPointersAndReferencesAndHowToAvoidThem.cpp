#include <iostream>
using namespace std;

//int * Func();
void Func(int * x);

int main() {

//  int * myPtr = nullptr;
//  *myPtr = 20;

//  int *xPtr = Func();
//
//  cout << "The value pointed to by xPtr is: " << *xPtr << endl;

  int x = 5;
  Func(&x);

  cout << "The value of x is: " << x << endl;

  return 0;
}

//int * Func()
//{
//  int x = 5;
//  return &x;
//}

void Func(int * x)
{
  int y = 10;

  x = &y;
}