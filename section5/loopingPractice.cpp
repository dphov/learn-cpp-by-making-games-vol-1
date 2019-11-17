#include <iostream>
using namespace std;

void problem1()
{
	// Problem 1: Write a program that will take in a number from the user
	// and print the reverse of that number. Eg input: 1234 -> output: 4321

	int number = 0;
	int reverse = 0;

	cout << "Please Enter a number: ";
	cin >> number;

	while(number > 0)
	{
		reverse = (reverse * 10) + (number % 10);
		cout<< " reverse " << reverse << endl;
		// 0 + 4
		// 40 + 3
		// 430 + 2
		// 4320 + 1
		// 4321
		number /= 10;
		cout<< " number " << number << endl;

	}


	cout << "The reverse is: " << reverse << endl;
}

void problem2()
{
	/* Problem 2: Write a problem that takes in two numbers from the user
	 * and prints a star pattern in a rectangular form
	 * The first number will be the number of rows
	 * The second number will be the number of columns
	 * e.g.
	 * if rows 5 and columns was 6
	 * ******
	 * ******
	 * ******
	 * ******
	 * ******
	*/

	int numberOfRows = 0;
	int numberOfCols = 0;

	cout << "Please enter the number of rows: ";
	cin >> numberOfRows;

	cout << "Please enter the number of columns: ";
	cin >> numberOfCols;

	for (int r = 0; r < numberOfRows; r++)
	{
		for (int c = 0; c < numberOfCols; c++)
		{
			cout << '*';
		}
		cout << endl;
	}

}

void problem3()
{
	/* Problem 3: Write a program that takes in a number and prints a pyramid star pattern.
	 * The pattern for 5 would look like this:
	 *      * 0
	 *     *** 1
	 *    ***** 2
	 *   ******* 3
	 *  ********* 4
	 */
	int number = 0;
	cout << "Please enter a number: ";
	cin >> number;

	for ( int i = 0; i < number; i++)
	{
		// print spaces
		for (int j = 0; j < (number - i - 1); j++)
		{
			cout << ' ';
		}

		// print the stars
		for (int j = 0; j < (2 * i + 1); j++)
		{
			cout << '*';
		}
		cout << endl;
	}
}
int main()
{
//	problem1();
//	problem2();
	problem3();
	return 0;


}