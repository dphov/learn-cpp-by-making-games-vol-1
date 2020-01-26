/*
 * main.cpp
 *
 * tic-tac-toe
 *
 * Created by Dmitry Petukhov on 04/01/2020.
 * Copyright Dmitry Petukhov, 2020.
*/

#include <iostream>
#include <tuple>

#include "Utils.h"

using namespace std;

bool PlayGame();
bool WantToPlayAgain(bool shouldQuitTheGame);

void DrawBoard(char *string1);
char *GetCharPosition(char *pString);
tuple<bool, bool> WriteCharToBoard(char *position, char *board, bool isPlayerOneTurn, char **messageString);
int ConvertPositionToIndex(char character, char number);
tuple<bool, char, char> ValidatePosition(char *position);
void PrintArray(char *board, int length);
bool IsGameOver(const char *board, int boardLength, bool shouldQuitTheGame);
void OutputMessage(char *basicString);
void PrintGameOverResult(bool isPlayerOneTurn, const char *board, int boardLength);
void OutputCurrentPlayersMessage(bool turn);

int main(int argc, char ** argv)
{
    bool shouldQuitTheGame;
    do
    {
        shouldQuitTheGame = PlayGame();
    }
    while(WantToPlayAgain(shouldQuitTheGame));
    return 0;
}

bool WantToPlayAgain(bool shouldQuitTheGame)
{
    if (shouldQuitTheGame)
        return false;
    else 
    {
        const char validInputs[] = {'y', 'n'};
        char response = GetCharacter("Do you want to play again? (y/n): ", "Wrong input, try again", validInputs, 2);
        return response == 'y';
    }
}

bool PlayGame()
{
    char *opBoard = new char[9];
    DrawBoard(opBoard);
    char *opPosition = new char[2];
    bool isPlayerOneTurn = true;
    char *opMessageString = new char;
    OutputCurrentPlayersMessage(isPlayerOneTurn);
    bool shouldQuitTheGame = false;
    do
    {
        GetCharPosition(opPosition);
        if (opPosition[0] != 'q' && opPosition[1] != 'u'  && opPosition[2] != 'i' && opPosition[3] != 't')
        {
            cout <<opPosition << endl;
            isPlayerOneTurn = get<0>(WriteCharToBoard(opPosition, opBoard, isPlayerOneTurn, &opMessageString));
            DrawBoard(opBoard);
            OutputCurrentPlayersMessage(isPlayerOneTurn);
        } else {
            shouldQuitTheGame = true;
        }
    }
    while(!IsGameOver(opBoard, 9, shouldQuitTheGame));

    if (!shouldQuitTheGame)
    {
        PrintGameOverResult(isPlayerOneTurn, opBoard, 9);
        return false;    
    } 
    else
    {
        cout << "See you soon!\n" << endl;
        return true;
    }
    
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

    if((board[0] && (board[0] == board[1] && board[1] == board[2]))
       || (board[3] && (board[3] == board[4] && board[4] == board[5]))
       || (board[6] && (board[6] == board[7] && board[7] == board[8])))
    {
        PrintTheWinner(isPlayerOneTurn);
        return;
    }
    else if((board[0] && (board[0] == board[3] && board[3] == board[6]))
            || (board[1] && (board[1] == board[4] && board[4] == board[7]))
            || (board[2] && (board[2] == board[5] && board[5] == board[8])))
    {
        PrintTheWinner(isPlayerOneTurn);
        return;
    }
    else if((board[0] && (board[0] == board[4] && board[4] == board[8]))
            || (board[6] && (board[6] == board[4] && board[4] == board[2])))
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

bool IsGameOver(const char *board, int boardLength, bool shouldQuitTheGame)
{
    if (shouldQuitTheGame)
    {
        return true;
    }

    int i = 0;
    while(board[i] && i <= boardLength)
    {
        i++;
    }

    if((board[0] && (board[0] == board[1] && board[1] == board[2]))
       || (board[3] && (board[3] == board[4] && board[4] == board[5]))
       || (board[6] && (board[6] == board[7] && board[7] == board[8])))
        return true;
    else if((board[0] && (board[0] == board[3] && board[3] == board[6]))
            || (board[1] && (board[1] == board[4] && board[4] == board[7]))
            || (board[2] && (board[2] == board[5] && board[5] == board[8])))
        return true;
    else if((board[0] && (board[0] == board[4] && board[4] == board[8]))
            || (board[6] && (board[6] == board[4] && board[4] == board[2])))
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