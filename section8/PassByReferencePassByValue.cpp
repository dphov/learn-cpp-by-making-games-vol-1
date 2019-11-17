#include <iostream>
using namespace std;


void Func(int & y);

int main() {
  int x = 5;
  Func(x);
  cout << "The value of x is: " << x << endl;

  return 0;
}

void Func(int & y) {
  y = 15;
  cout << "The value of y is: " << y << endl;
}