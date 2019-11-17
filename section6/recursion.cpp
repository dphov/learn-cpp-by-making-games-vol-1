#include <iostream>
using namespace std;

int Factorial(int number);

int main()
{
	int x = 5;
	cout << "The factorial of " << x << " is: " << Factorial(x) << endl;
	return 0;
}

int Factorial(int number)
{
	if(number == 1)
	{
		return 1;
	}
	return number * Factorial(number - 1);
}