#include <iostream>
using namespace std;

int main()
{
	const int MAX = 5;
	for (int i = 1; i <= MAX; i++)
	{
		cout << "Iteration i = " << i << endl;

		for (int j = 1; j <= MAX; j++)
		{
			cout << "Iteration j = " << j << endl;
		}
	}
	return 0;
}
