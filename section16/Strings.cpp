//
// Created by Dmitry Petukhov on 19/03/2020.
//

#include <iostream>
#include <string>

using namespace std;

void Func(const string& aString)


int main()
{
    string myString = "Hello";
    string myString2;

    cout << myString << endl;

    cout << "Please enter a string: ";
    cin >> myString2;

    cout << myString2 << endl;

    string myString3 = myString + myString2;

    myString3 += "!";

    cout << "Result: " << myString3 << endl;

    myString[0] = 'h'; // just like with cstrings

    cout << "The length of myString3 is: " << myString3.length() << endl;

    cout << "The cstring representation is: " << myString3.c_str() << endl;

    return 0;
}