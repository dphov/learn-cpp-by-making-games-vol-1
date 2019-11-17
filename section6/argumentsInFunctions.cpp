#include <iostream>
using namespace std;

void PrintValue(int x, char c, float y);

int main()
{
	int z = 10;
	PrintValue(10, 'a', 3.14);
	return 0;
}

void PrintValue(int x, char c, float y)
{
	cout << "The integer is: " << x << endl;
	cout << "The character is: " << c << endl;
	cout << "The float is: " << y << endl;
}