//
// Created by Dmitry Petukhov on 07/03/2020.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outFile;

    outFile.open("Test.txt");

    // << insertion operator
    outFile << "Hello File IO" << endl;

    outFile.close();
    return 0;
}