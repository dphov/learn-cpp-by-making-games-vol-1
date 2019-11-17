#include <iostream>
using namespace std;

int CalcVolumeOfRectangularPrism(int width, int length = 2, int height = 10);

int main()
{
	int width = 5;
	int length = 5;
	int height = 5;

	cout << "The volume is: " << CalcVolumeOfRectangularPrism(width);

	return 0;
}

int CalcVolumeOfRectangularPrism(int width, int length, int height)
{
	return width * length * height;
}

