#include <iostream>
using namespace std;

int main()
{
	int num; // input
	bool failure;
	const int IGNORE_CHARS = 256;
	do
	{
		failure = false;
		cout << "Please enter a number: ";
		cin >> num;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			failure = true;
			cout << "Input error! Please try again." << endl;
		}

	} while (failure);

	cout << "The number you inputted was: " << num << endl;
	return 0;
}