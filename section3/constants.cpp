#include <iostream>
using namespace std;

int main()
{
    const float PI = 3.14159;

    float radius;

    cout << "Please enter the radius of the circle: ";
    cin >> radius;
    cout << "The circumference of the circle is: " << 2 * PI * radius << endl;
    return 0;
}