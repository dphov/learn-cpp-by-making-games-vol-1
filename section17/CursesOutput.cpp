//
// Created by Dmitry Petukhov on 26/03/2020.
//

#include <iostream>
#include <ncurses.h>
#include <string>

using namespace std;

int main()
{
    initscr();
    curs_set(false);

    int windowMaxX = 0;
    int windowMaxY = 0;

    getmaxyx(stdscr, windowMaxY, windowMaxX);
    //    move(15, 10); // changes cursor position (y, x)

    //    printw("Hello, World!");

    string helloString = "Hello World";

    //    mvprintw(20, 15, "Hello, World!"); // c-string

    //LINES is the number of rows of our window
//    mvprintw(windowMaxY / 2, windowMaxX / 2 - helloString.length() / 2, helloString.c_str());

//    addch('*');

    mvaddch(15, 10, '*');

    clear();

    refresh();

    getch(); // pause

    endwin();

    return 0;
}