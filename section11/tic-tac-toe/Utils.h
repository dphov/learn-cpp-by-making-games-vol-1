/*
 * Utils.h
 *
 * tic-tac-toe
 *
 * Created by Dmitry Petukhov on 04/01/2020.
 * Copyright Dmitry Petukhov, 2020.
*/

#ifndef __UTILS_H__
#define __UTILS_H__

using namespace std;


   char GetCharacter(const char *prompt, const char *error);
   char GetCharacter(const char *prompt, const char *error, const char validInput[], int validInputLength);
   void ClearScreen();
   void WaitForKeyPress();
   char *GetCharacters(const char *prompt, const char *error, char *string);


#endif