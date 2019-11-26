#include <iostream>
using namespace std;

int main()
{
    // Example 1

    // int * ptr = new int;
    // delete ptr; // okay
    // but then...
    // delete ptr; // BAD!
    // Instead, do this.
    // ptr = nullptr; // GOOD!

    // Example 2
    //
    //    int x = 5;
    //    int * ptr = new int[10];

    //    NEVER DO THIS 1
    //    ptr = &x; // OOPS! - MEMORY LEAK!
    //    NEVER DO THIS 2
    //    cout << "address of the ptr: " << ptr << endl;
    //    ptr++; // now you don't point to the initial address
    //    cout << "address of the ptr: " << ptr << endl;
    //    delete [] ptr;
    //    Instead the second, do this.  Always access through different pointer
    // and keep the owning pointer the same
    //    int * ptr2 = ptr;
    //    cout << "address of the ptr: " << ptr2 << endl;
    //    ptr2++; // now you don't point to the initial address
    //    cout << "address of the ptr: " << ptr2 << endl;
    //    delete [] ptr;

    // EXAMPLE 3
    //    int * ptr = new int[10];
    //    ptr[11] = 4; // assigning your index range - VERY BAD!


    // EXAMPLE 4
//    int * ptr = new int;
//    delete [] ptr; // BAD

    return 0;
}