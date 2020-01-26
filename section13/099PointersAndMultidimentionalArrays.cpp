//
// Created by Dmitry Petukhov on 25/01/2020.
//

#include <iostream>
using namespace std;

int main()
{

    const int MAX = 10;
    // In memory this is next to each other
    // If you know the exact size, you should use the contiguous one because this is usually more efficient
//    int (*pointer)[MAX]  = new int [MAX] [MAX]; // Pointer to array of 10 items

    // Unlike this, they might be contiguous but maybe they're not
    // Ant this pretty flexible in terms of the row and column sizes
    int ** pointer = new int*[MAX];
    for(int r = 0; r < MAX; r++)
    {
        pointer[r] = new int[MAX];
    }

    for(int r = 0; r < MAX; r++ )
        for(int c = 0; c < MAX; c++)
        {
            pointer[r][c] = r * c;
            cout << "r= " << r << ", c = " << c << ", val = " << pointer[r][c] << endl;
        }

    for(int r = 0; r < MAX; r++)
    {
        delete [] pointer[r];
    }
    delete  [] pointer;
    return 0;
}