#include <iostream>
using namespace std;

int main()
{

    int length;

    cout << "Please enter a length: ";
    cin >> length;

    // create array syntax
    int * intPtr = new int[length];

    for(int i = 0; i < length; i++)
    {
        intPtr[i] = i + 1;
    }

    for (int i = 0; i < length; i++)
    {
        cout << "intPtr[" << i << "]: " << intPtr[i] << endl;
    }


    // delete array syntax
    delete [] intPtr;


    return 0;
}