
#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>

enum CharacterCaseType
{
  CC_UPPER_CASE = 0,
  CC_LOWER_CASE,
  CC_EITHER
};

char GetCharacter(const char * prompt, const char * error);
char GetCharacter(const char * prompt, const char * error, const char validInput[], int validInputLength, CharacterCaseType charCase);

int GetString(const char * prompt, const char * error, std::string & aString);

int GetInteger(const char * prompt, const char * error, const int validInput[], int validInputLength);

void ClearScreen();
void WaitForKeyPress();

#endif