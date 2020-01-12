#include <iostream>

using namespace std;

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
     *      hiddenPhrase[i] = guess;
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
    return 0
}