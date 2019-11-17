#include <iostream>
using namespace std;

int main()
{
	const int MAX = 100;
	for (int i = 1; i <= MAX; i++) {
		if (i % 2 == 0)
		{
			continue;
		}
		cout <<  "The current iteration is: " << i << endl;
	}
	return 0;
}