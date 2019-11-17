#include <iostream>
using namespace std;

int main()
{
  int x = 5;
  int y = 9;
  int max = 0;

  x > y ? max = x : max = y;


  cout << "The max is: " << max << endl;
  return 0;
}
