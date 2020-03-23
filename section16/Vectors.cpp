//
// Created by Dmitry Petukhov on 22/03/2020.
//


// C++ Vector is a dynamic array, and not a linear algebra vector!

#include <iostream>
#include <vector>

using namespace std;

// if you wanted to add or change in any way
// you should be passing it by reference
// otherwise if you pass it by value
// it will do that kind of very expensive copy
// if you don't want to change it you should pass it by constant reference
void Func(const vector<int> & vecRef);

int main()
{
    vector<int> intVec;

    intVec.reserve(20);

    intVec.push_back(5);


    for(int i = 0; i<20; i++)
    {
        intVec.push_back(5);
        cout << "The size of the vector: " << intVec.size() << endl;
        cout << "The capacity of the vector: " << intVec.capacity() << endl;
    }

    intVec.pop_back(); // remove the last element in the vector

    cout << "The size of the vector: " << intVec.size() << endl;
    cout << "The capacity of the vector: " << intVec.capacity() << endl;

    intVec.clear(); // remove all the elements in the vector

    if(intVec.empty())
    {
        cout << "the vector is empty" << endl;
    }
    else
    {
        cout << "the vector is not empty" << endl;
    }

    intVec[0] = 5;
    cout << "intVec[0]: " << intVec[0] << endl;

    return 0;
}
