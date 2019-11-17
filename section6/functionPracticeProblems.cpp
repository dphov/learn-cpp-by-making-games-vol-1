#include <iostream>
#include <vector>
using namespace std;



/*
 * This program takes a positive integer from user and stores it in variable n.
Then, for loop is executed which checks whether the number entered by user is perfectly divisible by i or not.
The for loop initiates with an initial value of i equals to 2 and increasing the value of i in each iteration.
If the number entered by user is perfectly divisible by i then, isPrime is set to false and the number will not be a prime number.
But, if the number is not perfectly divisible by i until test condition i <= n/2 is true means, it is only divisible by 1 and that number itself.
So, the given number is a prime number.
Check out these related examples:
 */
void problem1()
{
	/*
	 * Problem 1: Write a function that takes in an integer
	 * and returns true if the integer is a prime number.
	 */
	int num;
	cout << "Please enter the number to test: ";
	cin >> num;
	bool isPrime = true;

	for (int i = 2; i <= num / 2; ++i)
	{
		if ((num % i) == 0){
			isPrime = false;
			break;
		}
	}

	if (isPrime)
	{
		cout << "Is a prime number" << endl;
	}
	else
	{
		cout << "Is not a prime number" << endl;
	}

}

int problem2()
{
	/*
	 * Problem 2: Write a function to find all prime numbers between two intervals.
	Eg.

	Input lower limit: 10
	Input upper limit: 50
	Output prime numbers between 10-50 are: 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47
	 */

	int low;
	int high;
	cout << "Please enter the two numbers to test: ";
	cin >> low >> high;
	bool isPrime = true;
	vector<int> v;

	for (int j = low; j <= high; ++j)
	{
		for (int i = 2; i <= j / 2; ++i)
		{
			if ((j % i ) == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			v.push_back(j);
		isPrime = true;
	}
	for (int n: v)
		cout << n << " ";
	cout << endl;

}
int problem3()
{
	/*
	* Problem 3: Write a program to print pascal triangle up to n rows.

	Info about pascal triangles: Pascal Triangles

	For example Pascal triangle with 5 rows.
	    1       numbers count 1 - 1 = 0
	   1 1      numbers count 2 - 1 = calc 1 number
	  1 2 1     numbers count 3 - 1 = calc 2 numbers
	 1 3 3 1    numbers count 4 - 1 = calc 3 numbers
	1 4 6 4 1   numbers count 5 == max rows, stop.
	*/
	int num;

	cout << "Please enter number of rows for generating Pascal triangle: ";
	cin >> num;

	vector<vector<int>> vec(num,vector<int>(num));

	for(int i = 0; i < num; ++i)
	{
		vec[i][0] = 1;
		if (i > 0)
			vec[i][1] = i;
		if (i > 1)
			vec[i][i] = 1;
		if (i > 2)
			for (int j = 1; j < vec[i].size() - 1; ++j)
			{
				if ( vec[i][j] == 0)
				{
					vec[i][j] = vec[i-1][j-1] + vec[i-1][j];
				}
//				cout << vec[i][j];
			}
//		cout << endl;
	}

	for (int i = 0; i < vec.size(); i++)
	{

	}
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num - i; ++j)
		{
			cout << ' ';
		}
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j] != 0)
			{
				cout << ' ';
				cout << vec[i][j];
			}
		}
		cout << endl;
	}
}
int main()
{
	problem3();
	return 0;
}
