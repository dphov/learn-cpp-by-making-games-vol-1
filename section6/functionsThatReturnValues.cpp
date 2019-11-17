#include <iostream>
using namespace std;

int Square(int x);

int main()
{
	cout << "The square of 5 is:  " << Square(5) << endl;
	return 0;
}

int Square(int x)
{
	return x * x;
}