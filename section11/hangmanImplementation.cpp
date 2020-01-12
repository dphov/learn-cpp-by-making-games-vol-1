#include <iostream>
#include <cstring>
#include <cctype>

#include "Utils.h"

using namespace std;

const int IGNORE_CHARS = 256;

const char * INPUT_ERROR_STRING = "Input error! Please try again.";

void PlayGame();
bool WantToPlayAgain();
int GetSecretPhrase(char *secretPhrase, const int maxLength);
char * MakeHiddenPhrase(const char *secretPhrase, int secretPhraseLength);
void DrawBoard(int numberOfGuessesLeft, const char * noptrHiddenPhrase);

char GetGuess();
void UpdateBoard(char guess, char * noptrHiddenPhrase, const char secretPhrase[], int secretPhraseLength, int & numberOfGuessesLeft);
bool IsGameOver(int numberOfGuessesLeft, const char * noptrHiddenPhrase, int secretPhraseLength);

void DisplayResult(const char * secretPhrase, int numberOfGuessesLeft);

int main()
{
    /*
     * Create the program hangman. Prompt the player to enter a phrase.
     * That phrase will be hidden by a series of dashes (excluding spaces).
     * The player can then guess letters. If they guess correctly all the letters that match will be revealed.
     * If the guess incorrectly, then 1 more body part will be added to the gallows.
     * If they lose the gallows should look like this:
     *
     *  +---+
     *  |   |
     *  |   o
     *  |  /|\
     *  |  / \
     *  |
     * -+-
     *
     * If the player loses, the phrase should be revealed.
     * After the game is over the player should be prompted if they want to play again.
     */

    // we need a way of storing the secret phrase
    // we need a way of storing the hidden phrase (with dashes)
    // we need a variable that holds the number of guesses left (set to 6 initially)

    /*
     * Start with the highest concept level possible
     *
     * Step 1:
     * Main
     * ----
     * do
     * {
     *    PlayGame
     * } while (WantToPlayAgain)
     *
     * Step 2:
     *
     *  +---+
     *  |   |
     *  |
     *  |
     *  |
     *  |
     * -+-
     *
     * --e ----
     *
     * PlayGame
     * --------
     *
     * secretPhrase = GetSecretPhrase()
     * hiddenPhrase = MakeHiddenPhrase(secretPhrase)
     * numberOfGuessesLeft = 6
     *
     * DrawBoard(hiddenPhrase)
     *
     * do
     * {
     *  guess = GetGuess()
     *  UpdateBoard(guess, secretPhrase, hiddenPhrase, &numberOfGuessesLeft)
     *  DrawBoard(hiddenPhrase)
     *
     * } while (!GameIsOver(&numberOfGuessesLeft, hiddenPhrase))
     *
     * DisplayResult(secretPhrase, numberOfGuessesLeft)
     *
     * Step 3:
     *
     * GetSecretPhrase
     * --------------
     *
     * Prompt the user for the secret phrase
     * Get the secret phrase
     *
     * return secret phrase
     *
     * MakeHiddenPhrase(secretPhrase)
     * --------------------------------
     *
     * hiddenPhrase = make new cstring given the length of the secret phrase
     *
     * for (length of the secret phrase)
     * {
     *      hiddenPhrase[i] = '-'
     * }
     *
     * return hiddenPhrase
     *
     * UpdateBoard(guess, secretPhrase, hiddenPhrase, &numberOfGuessesLeft)
     * ------------
     *
     * bool found = false;
     *
     * for(length of the secretPhrase)
     * {
     *  if (secretPhrase[i] == guess)
     *  {
     *      hiddenPhrase[i] = secretPhrase[i];
     *      found = true;
     *  }
     * }
     * if(!found)
     *   numberOfGuessesLeft--;
     *
     *
     * IsGameOver(&numberOfGuessesLeft, hiddenPhrase)
     * -------------------------------------------------
     *
     * bool hasDash = false
     *
     * for(length of the hiddenPhrase && !hasDash)
     * {
     *      if(hiddenPhrase[i] == '-')
     *          hasDash = true
     * }
     *
     * return numberOfGuessesLeft == 0 || hasDash
     *
     */

    do
    {
        PlayGame();

    } while (WantToPlayAgain());

    return 0;
}

void PlayGame()
{
    const int MAX_LENGTH_OF_SECRET_PHRASE = 256;
    const int MAX_NUMBER_OF_GUESSES = 6;
    char secretPhrase[MAX_LENGTH_OF_SECRET_PHRASE];
    char * optrHiddenPhrase = nullptr; // making it from the HEAP memory
    int numberOfGuessesLeft = MAX_NUMBER_OF_GUESSES;

    int secretPhraseLength = GetSecretPhrase(secretPhrase, MAX_LENGTH_OF_SECRET_PHRASE);

    optrHiddenPhrase = MakeHiddenPhrase(secretPhrase, secretPhraseLength);

    DrawBoard(numberOfGuessesLeft, optrHiddenPhrase);

    char guess;


    do
    {
        guess = GetGuess();
        UpdateBoard(guess, optrHiddenPhrase, secretPhrase, secretPhraseLength, numberOfGuessesLeft);
        DrawBoard(numberOfGuessesLeft, optrHiddenPhrase);
    } while (!IsGameOver(numberOfGuessesLeft, optrHiddenPhrase, secretPhraseLength));

    DisplayResult(secretPhrase, numberOfGuessesLeft);

    delete [] optrHiddenPhrase;
}

char GetGuess()
{
    return GetCharacter("Please input your guess: ", INPUT_ERROR_STRING);
}

void UpdateBoard(char guess, char * noptrHiddenPhrase, const char secretPhrase[], int secretPhraseLength, int & numberOfGuessesLeft)
{
    bool found = false;

    for (int i = 0; i < secretPhraseLength; i++)
    {
        if (tolower(secretPhrase[i]) == guess)
        {
            noptrHiddenPhrase[i] = secretPhrase[i];
            found = true;
        }
    }

    if (!found)
    {
        numberOfGuessesLeft--;
    }
}

bool IsGameOver(int numberOfGuessesLeft, const char * noptrHiddenPhrase, int secretPhraseLength)
{
    bool hasDash = false;
    for (int i = 0; i < secretPhraseLength; i++)
    {
        if (noptrHiddenPhrase[i] == '-')
        {
            hasDash = true;
            break;
        }
    }

    return numberOfGuessesLeft == 0 || !hasDash;
}

void DisplayResult(const char * secretPhrase, int numberOfGuessesLeft)
{
    if (numberOfGuessesLeft > 0)
    {
        cout << "You got it! The word was: " << secretPhrase << endl;
    }
    else
    {
        cout << "You didn't get it.... The phrase was: " << secretPhrase << endl;
    }
}

bool WantToPlayAgain()
{
    const char validInputs[] = {'y','n'};

    char response = GetCharacter("Would you like to play again? (y/n) ", INPUT_ERROR_STRING, validInputs, 2);
    return response == 'y';
}

char * MakeHiddenPhrase(const char *secretPhrase, int secretPhraseLength)
{
    char * hiddenPhrase = new char[secretPhraseLength + 1];

    for (int i = 0; i < secretPhraseLength; i++)
    {
        if (secretPhrase[i] != ' ')
        {
            hiddenPhrase[i] = '-';
        }
        else
            hiddenPhrase[i] = ' ';
    }

    hiddenPhrase[secretPhraseLength] = '\0';

    return hiddenPhrase;
}

int GetSecretPhrase(char *secretPhrase, const int maxLength)
{
    bool failure;
    int length;
    do
    {
        failure = false;
        cout << "Please enter the secret phrase: ";
        cin.get(secretPhrase, maxLength);

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << INPUT_ERROR_STRING << endl;
            failure = true;
        }
        else
        {
            length = strlen(secretPhrase);
            if(length == 0)
            {
                cout << "You must enter a word that's longer than 0 characters! Please try again." << endl;
                failure = true;
            }
        }
    } while (failure);

    return length;
}

void DrawBoard(int numberOfGuessesLeft, const char * noptrHiddenPhrase)
{
    ClearScreen();

    switch(numberOfGuessesLeft)
    {
    case 0:
    {
        cout << " +---+" << endl;
        cout << " |   |" << endl;
        cout << " |   0" << endl;
        cout << " |  /|\\" << endl;
        cout << " |  / \\" << endl;
        cout << "-+-" << endl << endl;
    }
    break;
    case 1:
    {
        cout << " +---+" << endl;
        cout << " |   |" << endl;
        cout << " |   0" << endl;
        cout << " |  /|\\" << endl;
        cout << " |  /" << endl;
        cout << "-+-" << endl << endl;
    }
    break;
    case 2:
    {
        cout << " +---+" << endl;
        cout << " |   |" << endl;
        cout << " |   0" << endl;
        cout << " |  /|\\" << endl;
        cout << " |  " << endl;
        cout << "-+-" << endl << endl;
    }
    break;
    case 3:
    {
        cout << " +---+" << endl;
        cout << " |   |" << endl;
        cout << " |   0" << endl;
        cout << " |  /|" << endl;
        cout << " |  " << endl;
        cout << "-+-" << endl << endl;
    }
    break;
    case 4:
    {
        cout << " +---+" << endl;
        cout << " |   |" << endl;
        cout << " |   0" << endl;
        cout << " |   |" << endl;
        cout << " |  " << endl;
        cout << "-+-" << endl << endl;
    }
    break;
    case 5:
    {
        cout << " +---+" << endl;
        cout << " |   |" << endl;
        cout << " |   0" << endl;
        cout << " |  " << endl;
        cout << " |  " << endl;
        cout << "-+-" << endl << endl;
    }
    break;
    case 6:
    {
        cout << " +---+" << endl;
        cout << " |   |" << endl;
        cout << " |  " << endl;
        cout << " |  " << endl;
        cout << " |  " << endl;
        cout << "-+-" << endl << endl;
    }
    break;
    default:
        break;
    }

    cout << "Secret phrase: " << noptrHiddenPhrase << endl << endl;
}



