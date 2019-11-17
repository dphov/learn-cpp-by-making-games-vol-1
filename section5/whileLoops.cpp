#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	int i = 1;
	const  int MAX = 1000;
	while ( i <= MAX )
	{
		if ( i % 2 == 0 )
		{
			sum += i;
		}
		i++;
	}

	cout << "Sum of all even numbers from 1 to " << MAX << " is: " << sum << endl;

	return 0;
}