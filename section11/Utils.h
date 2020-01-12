
#ifndef __UTILS_H__
#define __UTILS_H__

char GetCharacter(const char *prompt, const char *error);

char GetCharacter(const char *prompt, const char *error, const char validInput[], int validInputLength);

void ClearScreen();

void WaitForKeyPress();

#endif