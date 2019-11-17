#include <iostream>
using namespace std;

int main()
{
  int x = 0;
  int y = 0;

  cout << "Please enter 2 numbers with a space between: ";
  cin >> x >> y;

  if ( x > y )
  {
    cout << "Case 1: The bigger number is: " << x << endl;
  } else if ( x < y )
  {
    cout << "Case 2: The bigger number is: " << y << endl;
  }
  else
  {
    cout << "Case 3: They must be equal" << endl;
  }
  return 0;
}
