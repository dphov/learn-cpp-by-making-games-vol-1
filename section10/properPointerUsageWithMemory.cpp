#include <iostream>
using namespace std;

int * Func();
void Use(int * noptrInt);

int main()
{
    // optr - stands for owning pointer
    int * optrNewInt = Func();
    Use(optrNewInt);
    delete optrNewInt;
    // you should always set pointer to nullptr after
    // dangling pointer
    optrNewInt = nullptr;

    return 0;
}

// noptr - stands for non owning pointer
void Use(int * noptrInt)
{
    // use the ptr
}

int * Func()
{
    // comes from the Heap
    return new int; // okay to do
}