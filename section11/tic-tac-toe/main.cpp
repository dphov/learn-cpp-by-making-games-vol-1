/*
 * main.cpp
 *
 * learn-cpp-by-making-games-vol-1
 * Created by Dmitry Petukhov on 04/01/2020.
 * Copyright Dmitry Petukhov, 2020.
*/
#include <iostream>
#include <tuple>

#include "Utils.h"

using namespace std;

void PlayGame();
bool WantToPlayAgain();
void DrawBoard(char *string1);

char *GetCharPosition(char *pString);
tuple<bool, bool> WriteCharToBoard(char *position, char *board, bool isPlayerOneTurn, char **messageString);
int ConvertPositionToIndex(char character, char number);
tuple<bool, char, char> ValidatePosition(char *position);

void PrintArray(char *board, int i);
bool IsGameOver(const char *board, int i);
void OutputMessage(char *basicString);
void PrintGameOverResult(bool turn, const char *string1, int i);
void OutputCurrentPlayersMessage(bool turn);
/*
 * Write the game of Tic Tac Toe.
 * It's a game with a 3 by 3 grid played by 2 players.
 * One player places O markers
 * and the other player places X markers.
 * Each player takes turns placing her/his
 * marker in order to get 3 of their markers
 * to line up on the board.
 * A player wins when 3 or their markers
 * line up either horizontally, vertically or diagonally.
 * If no player has their markers line up in that fashion,
 * and the board is full, then the game is called a "Cat Game".
 * Your program should output the winner of the game
 * or "Cat Game" if there was no winner.
 * The user should be prompted if
 * they would like to play again when the game is over.
 * If they choose to play again, the player
 * who started second last game should go first.
 *
 * Hint: We've only learned about linear arrays like this:
 * 0 1 2 3 4 5 6 7 8
 *
 * But we need a way to have a board that looks like this:
 *
 * 0 1 2
 * 3 4 5
 * 6 7 8
 *
 * We can make our linear array
 * act like a 2D grid
 * by having a set index pattern
 * as shown above where index 0
 * of our array would be the top left element on the board,
 * element 1 would be the top middle element and so on.
 * So the numbers in the 2D grid
 * are the indices of our array.
 * This will act like a 2D grid
 * even though we only have an array.
 *
 * Top down design:
 *
 * Step 1
 * Main
 * ---------
 *
 * do
 * {
 *     PlayGame();
 * }
 * while (WantToPlayAgain());
 *
 * Step 2:
 *
 *     A B C
 *    +-+-+-+
 *  1 |X| | |
 *    +-+-+-+
 *  2 | |O| |
 *    +-+-+-+
 *  3 | | |X|
 *    +-+-+-+
 *
 *  Player 1 turn
 *  Free position indexes:
 *  B1 C1 A2 C2 A3 B3
 *  Input: C3 #it should be inputed as column and row or it could be lowcased
 *
 *
    // how to store the state of the board
    // how to write data
    // how to calculate the game over state
 *
 *
 * PlayGame
 * -----------
 * initialize the game
 *
 * do
 * {
 *      prompt the player for input
 *      Get the input
 *      Update the game
 *      Draw the game
 * } while (Game is not over)
 *
 * WantToPlayAgain
 * -----------------
 * Prompt the player for input
 * Get the input
 * return true if the user wanted to play again
 *
 *
 */


int main()
{
    do
    {
        PlayGame();
    }
    while(WantToPlayAgain());
    return 0;
}

bool WantToPlayAgain()
{
    const char validInputs[] = {'y', 'n'};
    char response = GetCharacter("Do you want to play again? (y/n): ", "Wrong input, try again", validInputs, 2);
    return response == 'y';
}

void PlayGame()
{
    char *opBoard = new char[9];
    DrawBoard(opBoard);
    char *opPosition = new char[2];
    bool isPlayerOneTurn = true;
    char *opMessageString = new char;
    OutputCurrentPlayersMessage(isPlayerOneTurn);
    do
    {
        GetCharPosition(opPosition);
        isPlayerOneTurn = get<0>(WriteCharToBoard(opPosition, opBoard, isPlayerOneTurn, &opMessageString));
        DrawBoard(opBoard);
        OutputCurrentPlayersMessage(isPlayerOneTurn);
    }
    while(!IsGameOver(opBoard, 9));

    PrintGameOverResult(isPlayerOneTurn, opBoard, 9);
}
void OutputCurrentPlayersMessage(bool isPlayerOneTurn)
{
    if(isPlayerOneTurn)
        cout << "O player turn\n" << endl;
    else
        cout << "X player turn\n" << endl;
}

void PrintTheWinner(bool isPlayerOneTurn)
{
    if(!isPlayerOneTurn)
        cout << "O wins!\n" << endl;
    else
        cout << "X wins!\n" << endl;
}
void PrintGameOverResult(bool isPlayerOneTurn, const char *board, int boardLength)
{
    int i = 0;
    while(board[i] && i <= boardLength)
    {
        i++;
    }

    if(board[0] && (board[0] == board[1] && board[1] == board[2])
       || board[3] && (board[3] == board[4] && board[4] == board[5])
       || board[6] && (board[6] == board[7] && board[7] == board[8]))
    {
        PrintTheWinner(isPlayerOneTurn);
        return;
    }
    else if(board[0] && (board[0] == board[3] && board[3] == board[6])
            || board[1] && (board[1] == board[4] && board[4] == board[7])
            || board[2] && (board[2] == board[5] && board[5] == board[8]))
    {
        PrintTheWinner(isPlayerOneTurn);
        return;
    }
    else if(board[0] && (board[0] == board[4] && board[4] == board[8])
            || board[6] && (board[6] == board[4] && board[4] == board[2]))
    {
        PrintTheWinner(isPlayerOneTurn);
        return;
    }
    else
    {
        cout << "Cat game!\n" << endl;
        return;
    }
}
void OutputMessage(char *message)
{
    if(!message)
        return;
    cout << message << endl;
}
bool IsGameOver(const char *board, int boardLength)
{
    int i = 0;
    while(board[i] && i <= boardLength)
    {
        i++;
    }

    if(board[0] && (board[0] == board[1] && board[1] == board[2])
       || board[3] && (board[3] == board[4] && board[4] == board[5])
       || board[6] && (board[6] == board[7] && board[7] == board[8]))
        return true;
    else if(board[0] && (board[0] == board[3] && board[3] == board[6])
            || board[1] && (board[1] == board[4] && board[4] == board[7])
            || board[2] && (board[2] == board[5] && board[5] == board[8]))
        return true;
    else if(board[0] && (board[0] == board[4] && board[4] == board[8])
            || board[6] && (board[6] == board[4] && board[4] == board[2]))
        return true;

    return i == boardLength;
}

void PrintArray(char *board, int length)
{
    cout << "[ ";
    for(int i = 0; i < length + 1; i++)
    {

        if(i + 1 == length + 1)
            cout << board[i] << " ]" << endl;
        else
            cout << board[i] << ",";
    }
}

tuple<bool, bool> WriteCharToBoard(char *position, char *board, bool isPlayerOneTurn, char **message)
{
    std::tuple<bool, char, char> validationResult = ValidatePosition(position);
    bool isPositionValid = get<0>(validationResult);
    char character = get<1>(validationResult);
    char number = get<2>(validationResult);
    int targetIndex;

    if(isPositionValid)
        targetIndex = ConvertPositionToIndex(character, number);
    else
        return make_tuple(isPlayerOneTurn, true);

    if(board[targetIndex])
    {
        string stringForMsg = "Computer: Please, choose other position";
        *message = &stringForMsg[0];
        cout << &message << endl;
        return make_tuple(isPlayerOneTurn, true);
    }
    if(isPlayerOneTurn)
        board[targetIndex] = 'O';
    else
        board[targetIndex] = 'X';

    return make_tuple(!isPlayerOneTurn, false);
}

bool ValidatePositionWithCharTable(char character, char number)
{
    char charsTable[] = {'A', 'B', 'C'};
    char numbersTable[] = {'1', '2', '3'};

    bool isValidCharExist = false;
    bool isValidNumberExist = false;

    for(int i = 0; i < 3; i++)
    {
        if(charsTable[i] == character)
            isValidCharExist = true;
        if(numbersTable[i] == number)
            isValidNumberExist = true;
    }
    return isValidCharExist && isValidNumberExist;
}

std::tuple<bool, char, char> ValidatePosition(char *position)
{
    bool isPositionValid;

    if(isdigit(position[0]) && isalpha(position[1]))
    {
        isPositionValid = ValidatePositionWithCharTable(static_cast<char>(toupper(position[1])), position[0]);
        return make_tuple(isPositionValid, toupper(position[1]), position[0]);
    }
    else if(isalpha(position[0]) && isdigit(position[1]))
    {
        isPositionValid = ValidatePositionWithCharTable(static_cast<char>(toupper(position[0])), position[1]);
        return make_tuple(isPositionValid, toupper(position[0]), position[1]);
    }
    return make_tuple(false, '0', '0');
}

int ConvertPositionToIndex(char columnName, char rowName)
{
    char rowsNamesTable[] = {'1', '2', '3'};
    int rowsValues[] = {2, 5, 8};
    char columnsNamesTable[] = {'A', 'B', 'C'};
    int columnsValues[] = {-2, -1, 0};

    int rowValue = 0;
    int columnValue = 0;
    for(int i = 0; i < 3; i++)
    {
        if(rowsNamesTable[i] == rowName)
            rowValue = rowsValues[i];
        if(columnsNamesTable[i] == columnName)
            columnValue = columnsValues[i];
    }
    return rowValue + columnValue;
}

char *GetCharPosition(char *pString)
{
    return GetCharacters("Enter position: ", "oops", pString);
}

char DrawSpaceOrCharacter(char character)
{
    if(character)
    {
        return character;
    }
    else
    {
        return ' ';
    }
}

void DrawBoard(char *board)
{

    ClearScreen();
    int counter = 1;
    char bar = '|';
    cout << "   A B C" << endl;
    cout << "  +-+-+-+" << endl;
    for(int i = 0; i < 9; i++)
    {
        if(i == 0 || i == 3 || i == 6)
        {
            cout << counter << ' ' << bar;
            counter++;
        }
        cout << DrawSpaceOrCharacter(board[i]);
        cout << bar;

        if(i == 2 || i == 5 || i == 8)
        {
            cout << endl;
            cout << "  +-+-+-+" << endl;
        }
    }
}