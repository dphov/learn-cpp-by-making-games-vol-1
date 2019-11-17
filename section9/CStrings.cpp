#include <iostream>
using namespace std;

int StringLength(const char * aString);


int main()
{
  /*
  *              0   1   2   3   4   ...  n-1
  *            +---+---+---+---+---+     +---+
  * array name |   |   |   |   |   | ... |   |
  *            +---+---+---+---+---+     +---+
  *
  */

//  char aString[6];
//
//  aString[0] = 'H';
//  aString[1] = 'e';
//  aString[2] = 'l';
//  aString[3] = 'l';
//  aString[4] = 'o';
//  aString[5] = '\0';
//
//  const char * anotherString = "Hello";
//
//  cout << aString << endl;
//
//  cout << anotherString << endl;

  char cString[] = "Hello";

  cout << "The length of " << cString << " is: " << StringLength (cString) << endl;

  return 0;
}

int StringLength(const char * aString)
{
  int length = 0;
  const char* p = aString;

  if (aString != nullptr)
    {
      while (*p != '\0')
        {
          length++;
          p++;
        }
    }
  return length;
}