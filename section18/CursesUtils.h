//
// Created by Dmitry Petukhov on 28/03/2020.
//

#ifndef _CURSESUTILS_H_
#define _CURSESUTILS_H_

#include <ncurses.h>

enum ArrowKeys
{
  UP = KEY_UP,
  DOWN = KEY_DOWN,
  LEFT = KEY_LEFT,
  RIGHT = KEY_RIGHT
};

void InitializeCurses(bool nodelay);
void ShutdownCurses();
void ClearScreen();
void RefreshScreen();
int ScreenWidth();
int ScreenHeight();
int GetChar();
void DrawCharacter(int xPos, int yPos, char aCharacter);
void MoveCursor(int xPos, int yPos);

#endif //_CURSESUTILS_H_
