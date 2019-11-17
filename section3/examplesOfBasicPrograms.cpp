#include <iostream>
using namespace std;

int main()
{
    // Problem 1: Write an algorithm that takes the temperature
    // in fahrenheit and outputs it in celsius
//    float celcius;
//    float fahrenheit;
//
//    cout << "Please enter a fahrenheit value: ";
//    cin >> fahrenheit;
//
//    celcius = ((fahrenheit - 32.0) * 5.0) / 9.0;
//
//    cout << fahrenheit << " in celcius is: " << celcius << endl;

// Problem 2: Write a program that takes three numbers and prints
// the average

//    float num1;
//    float num2;
//    float num3;
//
//    cout << "Please enter 3 numbers separated by spaces: ";
//    cin >> num1 >> num2 >> num3;
//
//    float average = (num1 + num2 + num3) / 3.0;
//
//    cout << "The average is: " << average << endl;

// Problem 3: Write a program that takes in a character and outputs its ASCII value.

    char charInput;
    cout << "Please enter a character: ";
    cin >> charInput;

    int value = charInput;

    cout << "The ASCII value of " << charInput << " is: " << value << endl;

    return 0;
}