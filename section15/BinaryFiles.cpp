//
// Created by Dmitry Petukhov on 08/03/2020.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Data
{
  int value1;
  int value2;
};

int main()
{
    srand(time(NULL));

    const int MAX = 10;

    const int VALUE1_MAX = 100;
    const int VALUE2_MAX = 1000;

    Data arrayData[MAX]; // not dynamic, so made on stack

    for(int i = 0; i < MAX; i++)
    {
        arrayData[i].value1 = rand() % VALUE1_MAX + 1;
        arrayData[i].value2 = (rand() % (VALUE2_MAX - VALUE1_MAX)) + VALUE1_MAX + 1;

        cout << "arrayData[" << i << "].value1: " << arrayData[i].value1 << endl;
        cout << "arrayData[" << i << "].value2: " << arrayData[i].value2 << endl;
    }

    ofstream outFile;

    outFile.open("Data.bin", fstream::binary);
    outFile.write((char *)&arrayData, sizeof(arrayData));
    outFile.close();

    Data newArray[MAX];

    ifstream inFile;

    inFile.open("Data.bin", fstream::binary);
    inFile.read((char*)&newArray, sizeof(newArray));
    inFile.close();


    for(int i = 0; i < MAX; i++)
    {
        cout << "newArray[" << i << "].value1: " << newArray[i].value1 << endl;
        cout << "newArray[" << i << "].value2: " << newArray[i].value2 << endl;
    }



    return 0;
}