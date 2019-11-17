#include <iostream>
#include <vector>

using namespace std;

void problem1()
{
// Problem 1:
// Write a program that inputs a character
// and outputs whether or not it is in the alphabet or not.
//
	char c;
	int intChar;
	cout << "Enter a character: ";
	cin >> c;
	intChar = int(c);
	if ((intChar >= 65 && intChar <= 90) || (intChar >= 97 && intChar <= 122)) {
		cout << " Char " << c << " is in ABC " << endl;
	} else {
		cout << "Char is not in ABC" << endl;
	}
}
void problem2()
{
	// Problem 2: Write a program that takes in 3 numbers
	// and outputs the biggest number and the smallest number.
	//
	vector<float> v(3, 0);
	cout << "Enter three numbers ";
	cin >> v[0] >> v[1] >> v[2];

	cout << "Max num is: " << *max_element(begin(v), end(v))
	<< " and min num is: " << *min_element(begin(v), end(v)) << endl;

}

void problem3()
{
// Problem 3: Write a program that enters 3 sides of a triangle
// checks whether the triangle is valid or not.
// Remember that a triangle is valid if and only
// if the sum of any two sides is greater than the third side.
//
	vector<float> v(3, 0);
	cout << "Enter three numbers ";
	cin >> v[0] >> v[1] >> v[2];

	if ((v[0] + v[1] >= v[2]) && (v[2] + v[1] >= v[0])) {
		cout << "The triangle is valid" << endl;
	} else {
		cout << "The triangle is not valid" << endl;
	}
}

void problem4()
{
// Problem 4: Write a program to enter any alphabet
// and check whether alphabet is vowel or consonant using switch case.
	char c;
	int intChar;
	vector<char> vowels = {'A', 'E', 'I', 'O', 'U',
							'a', 'e', 'i', 'o', 'u'};

	cout << "Enter a character: ";
	cin >> c;
	intChar = int(c);
	if ((intChar>=65 && intChar<=90) || (intChar>=97 && intChar<=122)) {
		char c1 = *find(begin(vowels), end(vowels), c);
		if (isalnum(c1)) {
			cout << c << " is Vowel" << endl;
		} else {
			cout << c << " is Consonant" << endl;
		}
	}
}
int main()
{
//	problem1();
//  problem2();
//  problem3();
  problem4();
  return 0;
}