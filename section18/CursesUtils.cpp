//
// Created by Dmitry Petukhov on 28/03/2020.
//

#include "CursesUtils.h"
#include <ncurses.h>

void CursesUtils::InitializeCurses(bool noDelay)
{
    initscr();
    noecho();
    curs_set(false);
    nodelay(stdscr, noDelay);
    keypad(stdscr, true);
}

void CursesUtils::ShutdownCurses()
{
    endwin();
}

void CursesUtils::ClearScreen()
{
    clear();
}

void CursesUtils::RefreshScreen()
{
    refresh();
}

int CursesUtils::ScreenWidth()
{
    return COLS;
}

int CursesUtils::ScreenHeight()
{
    return LINES;
}

int CursesUtils::GetChar()
{
    return getch();
}

void CursesUtils::DrawCharacter(int xPos, int yPos, char aCharacter)
{
    mvaddch(yPos, xPos, aCharacter);
}

void CursesUtils::MoveCursor(int xPos, int yPos)
{
    move(yPos, xPos);
}

void CursesUtils::DrawSprite(int xPos, int yPos, const char *sprite[], int spriteHeight, int offset)
{
    for(int h = 0; h < spriteHeight; h++)
    {
        mvprintw(yPos + h, xPos, "%s", sprite[h+offset]);
    }
}
