//
// Created by Dmitry Petukhov on 29/11/2019.
//

#include <iostream>
#include <cstring>

using namespace std;

char * ReverseCopy(char * phrase);

int main()
{
    // Problem 1: Read a phrase from the user and output it again
    const int MAX_BUFFER_LENGTH = 256;
    char buffer[MAX_BUFFER_LENGTH];

    cout << "Please enter a phrase: ";
    cin.get(buffer, MAX_BUFFER_LENGTH-1);

    cout << "Your input was: " << buffer << endl;

    // Problem 2: Using problem 1, make a function that will take in the input phrase
    // and returns a reverse copy of the phrase and outputs it

    char * optrReversePhrase = ReverseCopy(buffer);

    cout << "The phrase was: " << optrReversePhrase << endl;

    delete [] optrReversePhrase;

    return 0;
}

char * ReverseCopy(char * phrase)
{
    int length = strlen(phrase);

    char * reverseString = new char [length + 1]; //+1 for the null character

    int j = 0;

    for(int i = length - 1; i >= 0; i--)
    {
        reverseString[j] = phrase[i];
        j++;
    }

    reverseString[j] = '\0';
    return reverseString;
}