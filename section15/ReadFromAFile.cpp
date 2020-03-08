//
// Created by Dmitry Petukhov on 07/03/2020.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFile;

    inFile.open("Test.txt");

    if(inFile.is_open())
    {
        inFile.seekg(0, inFile.end); // move the cursor of the file to the end of the file
        int length = inFile.tellg();          // give the position of the current character character
        inFile.seekg(0, inFile.beg); // move the cursor to the start of the file

        char * optrBuffer = new char[length + 1];

        inFile.get(optrBuffer, length); // get() will put the null character at the end

        cout << optrBuffer << endl;

        delete [] optrBuffer;

        inFile.close();
    }
}