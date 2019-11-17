#include <iostream>
using namespace std;

int main()
{
	int i = 1;
	const int MAX = 10;

	while (i <= MAX)
	{
		cout << "The current iteration is: " << i << endl;
		i++;
	}

	for (int i = 1; i <= MAX; i++)
	{
		cout << "The current iteration is: " << i << endl;

	}

	return 0;
}