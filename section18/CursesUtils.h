//
// Created by Dmitry Petukhov on 28/03/2020.
//

#ifndef _CURSESUTILS_H_
#define _CURSESUTILS_H_

#include <ncurses.h>
namespace CursesUtils {
    enum ArrowKeys
    {
      AK_UP = KEY_UP,
      AK_DOWN = KEY_DOWN,
      AK_LEFT = KEY_LEFT,
      AK_RIGHT = KEY_RIGHT
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
    void DrawSprite(int xPos, int yPos, const char * sprite[], int spriteHeight, int offset = 0);
}
#endif //_CURSESUTILS_H_
