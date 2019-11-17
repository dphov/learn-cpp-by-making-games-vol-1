#include <iostream>
using namespace std;

int x = 5;

void Func();

int main()
{

	cout << "x is: " << x << endl;
	Func();
	return 0;
}

void Func()
{
	cout << "Func x is: " << x << endl;
}
