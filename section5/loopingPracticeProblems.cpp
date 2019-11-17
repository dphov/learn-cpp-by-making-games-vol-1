#include <iostream>
#include <vector>
using namespace std;

void problem1()
{
	/* Problem 1: Write a program to read binary number
	 * from user and find the one's complement of that binary number.

	Example:
	Input binary number: 01000011
	Ones's complement: 10111100
	*/

	string binaryNumStr = "";

	cout << "Please enter a binary number: ";
	cin >> binaryNumStr;
	for (int i = 0; i < binaryNumStr.length(); i++ )
	{
		cout << ((binaryNumStr[i] == '0') ? '1' : '0');
	}
	cout << endl;
}

/*
Problem 2: Write a program to print ASCII values of all characters using for loop.

Example:
Output ASCII values:
ASCII value of character = 0
ASCII value of character ☺ = 1
ASCII value of character ☻ = 2
*/

void problem2()
{
	cout << "Output ASCII values:" << endl;

	for (int i = 0; i <= 127; i++)
	{
		cout << "ASCII value of character " << char(i) << " = " << i << endl;
	}
}

/*
Problem 3: Write a program to count frequency of digits in an integer.

Example:
Input num: 116540
Output:
Frequency of 0 = 1
Frequency of 1 = 2
Frequency of 2 = 0
Frequency of 3 = 0
Frequency of 4 = 1
Frequency of 5 = 1
Frequency of 6 = 1
Frequency of 7 = 0
Frequency of 8 = 0
Frequency of 9 = 0

 */
void problem3()
{
	string input = "";

	vector<int> freq_of_chars(10);

	cout << "Please input a number: ";
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		switch  (input[i])
		{
		case '0': freq_of_chars[0] += 1; break;
		case '1': freq_of_chars[1] += 1; break;
		case '2': freq_of_chars[2] += 1; break;
		case '3': freq_of_chars[3] += 1; break;
		case '4': freq_of_chars[4] += 1; break;
		case '5': freq_of_chars[5] += 1; break;
		case '6': freq_of_chars[6] += 1; break;
		case '7': freq_of_chars[7] += 1; break;
		case '8': freq_of_chars[8] += 1; break;
		case '9': freq_of_chars[9] += 1; break;
		}
	}
	for (int i = 0; i < freq_of_chars.size(); i++)
	{
		cout << "Frequency of " << i << " = " << freq_of_chars[i] << endl;
	}

}
/*
Problem 4: Write a program to enter any number
 and check whether given number is palindrome
 or not using a for loop. Eg 121 would be a palindrome.
*/

void problem4()
{
	string input = "";
	cout << "Please input a number: ";
	cin >> input;

	string reversed(input.rbegin(), input.rend());
	if (input == reversed) {
		cout << "It's a palindrome" << endl;
	} else {
		cout << "It's a just a number" << endl;
	}
}

/*
Problem 5: Write a program to print the diamond star(*) pattern based on an input number.
*/

void problem5()
{
	int input = 0;
	cout << "Please input a number: ";
	cin >> input;

	int rows = input * 2 - 1;

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input - ( i + 1) ; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < ( i * 2 ) + 1; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
	for (int i = input - 2; i >= 0; i--)
	{
		for (int j = 0; j < input - ( i + 1) ; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < ( i * 2 ) + 1; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
}
/*
Problem 6: Write a program to print hollow diamond star (*) pattern series of n rows using for loop. The pattern for 5 should look like:
*/

void problem6()
{
	int input = 0;
	cout << "Please input a number: ";
	cin >> input;

	int rows = input * 2 - 1;

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input - ( i ) ; j++)
		{
			cout << '*';
		}
		for (int j = 0; j < ( i * 2 ); j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < input - ( i ) ; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
	for (int i = input - 2; i >= 0; i--)
	{
		for (int j = 0; j < input - ( i ) ; j++)
		{
			cout << '*';
		}
		for (int j = 0; j < ( i * 2 ) ; j++)
		{
			cout << ' ';
		}
		for (int j = 0; j < input - ( i ) ; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
}
int main()
{
	problem6();
	return 0;
}
