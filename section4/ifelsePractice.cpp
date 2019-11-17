//
// Created by Dmitry Petukhov on 2019-08-25.
//

#include <iostream>
#include <cmath>

using namespace std;

void problem1()
{
  // Problem 1: What does result evaluate to?

  int x = 0;
  int y = 20;

  bool z = true;
  bool w = false;

  bool result = (!w || z) && !((y > x) && (!z));
  cout << "The value of result is: " << result << endl;
}

void problem2()
{
  // Problem 2:

  // Write a program that finds all roots of the quadratic equation.
  // A quadratic equation is in the form ax^2 + bx + c = 0
  // The quadratic equation: (-b + squareroot(b * b - 4 * a * c)) / ( 2 * a )
  // and (-b - squareroot(b * b - 4 * a * c)) / (2 * a)

  // case 1: discriminant is positive - real root
  // case 2: discriminant is zero
  // case 3: discriminant is negative

  float a;
  float b;
  float c;

  float root1;
  float root2;
  float imaginary;

  float discriminant;

  cout << "Enter the values a, b and c of the quadratic equation (aX^2 + bX + c = 0): ";
  cin >> a >> b >> c;

  discriminant = (b * b) - (4 * a * c);

  if (discriminant > 0) // positive case
  {
    root1 = (-b + sqrt(discriminant)) / ( 2 * a );
    root2 = (-b - sqrt(discriminant)) / ( 2 * a );

    cout << "Two distinct in real roots exists: " << root1 <<  " and " << root2;

  }
  else if (discriminant < 0)
  {
    root1 = -b / 2 * a;
    root2 = root1;

    imaginary = sqrt(-discriminant) / (2 * a);
    cout << "Two distinct complex roots exist: " << root1 << " + i" << imaginary << " and " << root2 << " - i" << imaginary;
  }
  else
  {
    root1 = -b / 2 * a;
    root2 = root1;

    cout << "Two equal and real roots exist: " << root1 << " and " << root2;
  }
}

void problem3()
{
  // Problem 3:
  // Write a program that enters a number and prints out whether it's even or odd.
  // Use a switch statement.

  int number = 0;
  cout << "Enter any number if it's even or odd: ";
  cin >> number;

  int result = number % 2;

  switch (result)
  {
  case 0:
    cout << "Number is even";
    break;
  case 1:
    cout << "Number is odd";
    break;
  }
}

int main()
{
//  problem1();
//  problem2();
  problem3();
  return 0;
}