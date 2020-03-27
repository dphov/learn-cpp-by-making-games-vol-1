//
// Created by Dmitry Petukhov on 27/03/2020.
//

#include <iostream>
#include <ncurses.h>

using namespace std;

int main()
{
    initscr();

    curs_set(false);
    noecho();
    nodelay(stdscr, true); // true means no delay
    keypad(stdscr, true); // enable the arrow keys // dont blocking at all on my system
    
    
    
    bool quit = false;
    int input;

    while (!quit)
    {
        input = getch();
        
        if (input == KEY_DOWN) // KEY_UP, KEY_LEFT, KEY_RIGHT
        {
            quit = true;
        }
    
        mvprintw(20, 20, "Hello Everyone");
        refresh();
    
    }
    

    endwin();

    return 0;
}