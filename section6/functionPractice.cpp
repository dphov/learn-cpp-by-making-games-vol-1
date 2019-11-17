#include <iostream>
using namespace std;

double Diameter(double radius);
double Circumference(double radius);
double Area(double radius);

const double PI = 3.14159;

void problem1()
{
	/*
	 *  Problem 1: write a program that takes a radius as input and calculations the diameter.
	 *  the circumference and area of the given circle using functions.
	 */
	double radius;

	cout << "Please enter the radius of a circle";
	cin >> radius;

	cout << "The diameter of the circle is " << Diameter(radius) << endl;
	cout << "The circumference of the circle is: " << Circumference(radius) << endl;
	cout << "The area of the circle is: " << Area(radius) << endl;
}



double Diameter(double radius)
{
	return  2.0 * radius;
}
double Circumference(double radius)
{
	return  2.0 * radius * PI;
}
double Area(double radius)
{
	return  PI * radius * radius;
}

int GetIntegerFromUser();
void problem2()
{
 /*
  * PROBLEM 2: Write a function that gets an integer from the user. Do all appropriate error checking.
  */

	int number = GetIntegerFromUser();
	cout << "The number we got was: " << number << endl;
}

int GetIntegerFromUser()
{
	bool failure;
	int number;
	const int IGNORE_CHARS = 256;


	do
	{
		failure = false;
		cout << "Pleaser enter an integer: ";
		cin >>  number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << "Input error! Please try again" << endl;
			failure = true;
		}
	} while (failure);
	return  number;
}


int main()
{
	problem2();
	return 0;
}