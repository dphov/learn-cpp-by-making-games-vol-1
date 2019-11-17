#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/*
 * The game of 8 is played by 2 players.
 * The game starts with the initial number 8
 * (from here on refereed to as the initial number)
 * The first player will choose a number from 1 to 3
 * (from here on refereed to as the chosen number).
 * If the player inputs something
 * outside of the 1 to 3 range it should be an error
 * and the player must choose again. The initial number
 * is subtracted by the chosen number. Then the next player's turn happens.
 * The next player cannot choose the number that the last player chose.
 * If the initial number goes to 0 on your turn, then you win.
 * Otherwise if the number goes below 0, your opponent wins.
 * The player should always see what choices are available to him
 * when prompted to enter his choice. After the game is over, the user
 * should be prompted whether they want to play again.
 *
 * Write a program to solve this problem.
 *
 */

void PlayGame();
bool WantToPlayAgain();
bool IsNotGameOver(int initialNumber);
int getPlayerChoice(bool &isPlayerOneTurn, vector<int> numbersRange, int previouslyUsedNumber);
bool isValidPlayerChoice(int playerChoice, int previousPlayerChoice);
void displayResult(int playerChoice, int initialNumber, bool isPlayerOneTurn);
void displayEndGameResult(bool isPlayerOneTurn, int initialNumber);

const int IGNORE_CHARS = 256;

void erase(vector<int>& v, int num)
{
  size_t j = 0;
  for (size_t i = 0; i < v.size(); ++i)
  {
    if (v[i] != num) v[j++] = v[i];
  }
  v.resize(j);
}

int main()
{
    /*

     do
     {
        Play The Game
     } while (want to play again)

     Play the Game:
     1. Set the initial number 8

     do
     {
        2. Prompt the player one to choose the number from 1 to 3
        3. Get the choice from the player one
            3a. If it's outside of range 1 to 3
                3a1. Show the error and show prompt to the player one again (2.)
            3b. Else, the initial number is subtracted by the chosen.
        4. The player two should choose number from 1 to 3, except the number, chosen by the player one
        5. The initial number is subtracted by the chosen.
            5a. If the initial number goes to 0 and it was your turn, you win
            5b. If the initial number goes below 0, your opponent wins.


     }  while ( the game is not over)

     Display the result - tell the player if he got it or not

     Functions:

     Play the game -> PlayGame()

     Want to play again -> WantToPlayAgain()

     Get the number from the player -> GetNumber()

     Game is not over -> IsGameOver()

     initial number < 0 (player lose) || initial number == 0 (player win)

     Display result -> DisplayResult()

     if (the player got it)
     {
      print that they got in and print the initial number
     }
     else
     {
      print that they didn't get int and print the secret number
     }

     */



    do
    {
        PlayGame();
    } while (WantToPlayAgain());

    return 0;
}


void PlayGame()
{
  int initialNumber = 8;
  bool isPlayerOneTurn = true;
  vector<int> numbersRange = { 1, 2, 3 };
  int previousPlayerChoice = 0;
  int playerChoice = 0;

  cout << "The initial number is: " << initialNumber << endl;
  do
  {

    playerChoice = getPlayerChoice(isPlayerOneTurn, numbersRange, previousPlayerChoice);

    if (isValidPlayerChoice(playerChoice, previousPlayerChoice))
    {
      isPlayerOneTurn = !isPlayerOneTurn;
      previousPlayerChoice = playerChoice;
      initialNumber -= playerChoice;
      displayResult(playerChoice, initialNumber, isPlayerOneTurn);
    }
    else
    {
      cout << "KO" << endl;
    }
  } while (IsNotGameOver(initialNumber));

  displayEndGameResult(isPlayerOneTurn, initialNumber);
}

bool WantToPlayAgain()
{
  char input;
  bool failure;

  do
    {
    failure = false;
    cout << "Do you want to play again? (y/n): ";
    cin >> input;

    if (cin.fail())
    {
      cin.clear();
      cin.ignore(IGNORE_CHARS, '\n');
      cout << "Input Error! Please try again." << endl;
      failure = true;
    } else
    {
      cin.ignore(IGNORE_CHARS, '\n');
      input = tolower(input);
    }

    } while (failure);


  return input == 'y';
}

bool IsNotGameOver(int initialNumber)
{
  return initialNumber > 0;
}

int getPlayerChoice(bool &isPlayerOneTurn, vector<int> numbersRange, int previouslyUsedNumber)
{
  int playerChoice;
  if (previouslyUsedNumber == 0)
  {
    cout << "" << (isPlayerOneTurn ? "Player One: " : "Player Two")
         << "Please select the number from " << numbersRange.front() << " to "
         << numbersRange.back() << ": ";
    cin >> playerChoice;
  }
  else
  {
    erase(numbersRange, previouslyUsedNumber);
    cout << "" << (isPlayerOneTurn ? "Player One: " : "Player Two: ")
         << "Please select the number from these "
         << numbersRange[0] << ", " << numbersRange[1]
         << ": ";
    cin >> playerChoice;
  }
  return playerChoice;
}


bool isValidPlayerChoice(int playerChoice, int previousPlayerChoice)
{
  return (1 <= playerChoice) && (3 >= playerChoice) && previousPlayerChoice != playerChoice;
}

void displayResult(int playerChoice, int initialNumber, bool isPlayerOneTurn)
{
  cout << "" << (!isPlayerOneTurn ? "Player One " : "Player Two ")
  << "has chosen number " << playerChoice
  << ". " << "Now initial number is: " << initialNumber << endl;
}

void displayEndGameResult(bool isPlayerOneTurn, int initialNumber)
{
  if (initialNumber < 0)
  {
    cout << (!isPlayerOneTurn ? "Player One: " : "Player Two: ") << "lose the game! "
    << (isPlayerOneTurn ? "player one " : "player two ") << "wins!"
    << endl;
  }
  else
  {
    cout << (!isPlayerOneTurn ? "Player One: " : "Player Two: ") << "win the game! "
         << (isPlayerOneTurn ? "player one " : "player two ") << "lose!"
    << endl;
  }

}
