#include <iostream>
using namespace std;


void Print(int x);
void Print(char c);
void Print(int x, char c);

int main()
{
	Print(100);
	Print('A');
	Print(200, 'B');

	return 0;
}

void Print(int x)
{
	cout << "Printing integer: " << x << endl;
}

void Print(char c)
{
	cout << "Printing character: " << c << endl;
}

void Print(int x, char c)
{
	cout << "Printing integer: " << x << endl;
	cout << "Printing character: " << c << endl;

}
