#include <iostream>
using namespace std;

int main()
{
    // new will fetch memory from the heap
    // and return it as a pointer to a new memory
    int * newIntPtr = new int;

    *newIntPtr = 8;

    cout << "The value of my new integer is: " << *newIntPtr << endl;

    // delete the memory pointed to
    // by newIntPtr
    // You should always delete the memory
    delete newIntPtr;


    return 0;
}