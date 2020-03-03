//
// Created by Dmitry Petukhov on 24/12/2019.
//

#include "Utils.h"
#include <iostream>
#include <cctype>


#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define OS_WIN
#endif

using namespace std;

char GetCharacter(const char *prompt, const char *error)
{
    const int IGNORE_CHARS = 256;

    char input;
    bool failure;

    do
    {
        failure = false;
        cout << prompt;
        cin >> input;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << error << endl;
            failure = true;
        }
        else
        {
            cin.ignore(IGNORE_CHARS, '\n');
            if(isalpha(input))
            {
                input = tolower(input);
            }
            else
            {
                cout << error << endl;
                failure = true;
            }
        }
    }
    while(failure);
    return input;
}

char GetCharacter(const char *prompt, const char *error, const char validInput[], int validInputLength, CharacterCaseType charCase)
{
    const int IGNORE_CHARS = 256;

    char input;
    bool failure;

    do
    {
        failure = false;
        cout << prompt;
        cin >> input;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << error << endl;
            failure = true;
        }
        else
        {
            cin.ignore(IGNORE_CHARS, '\n');

            if(isalpha(input))
            {
                if(charCase == CC_UPPER_CASE)
                {
                    input = toupper(input);
                }
                else if (charCase == CC_LOWER_CASE)
                {
                    input = tolower(input);
                }


                for(int i = 0; i < validInputLength; i++)
                {
                    if(input == validInput[i])
                    {
                        return input;
                    }
                }
            }

            cout << error << endl;
            failure = true;
        }
    }
    while(failure);
    return input;
}

int GetInteger(const char *prompt, const char *error, const int validInput[], int validInputLength)
{
    int input;
    bool inputFailure;

    const int IGNORE_CHARS = 256;
    do
    {
        inputFailure = false;
        cout << prompt;
        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << error << endl;
            inputFailure = true;
        }
        else
        {
            for(int i = 0; validInputLength; i++)
            {
                if(input == validInput[i])
                {
                    return input;
                }
            }

            cout << error << endl;
            inputFailure = true;
        }
    } while (inputFailure);
    return -1;
}


void ClearScreen()
{
#ifdef OS_WIN
    system("cls");
#else
    system("clear");
#endif
}

void WaitForKeyPress()
{
#ifdef OS_WIN
    system("pause");
#else
    system("read -n 1 -s -p \"Press any key to continue...\";echo");
#endif
}
