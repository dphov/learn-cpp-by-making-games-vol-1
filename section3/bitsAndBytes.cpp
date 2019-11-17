#include <iostream>
using namespace std;

int main()
{
    // 1001
    // 4 bits binary number to 10base
    // (1 * 2^3) + (0 * 2^2) + (0 * 2^1) + (1 * 2^0) = 8 + 0 + 0 + 1 = 9

    //sizeof()
//
//    cout <<  " the size of an int is: " << sizeof(int) << endl;
//    cout << " the size of a char is: " << sizeof(char) << endl;
//    cout << " the size of a float is: " << sizeof(float) << endl;
//    cout << " the size of a double is: " << sizeof(double) << endl;

    // int -> -2^31 to 2^31 - 1 ( -1 because of 0)

    int intVal = 6; // 0  to 2^32-1 it's 32 bits   (-1 because of zero)

    float floatVal = 3.14;

    floatVal = intVal;
    cout<<"The value of floatVal is: "<< floatVal << endl;
    return 0;
}