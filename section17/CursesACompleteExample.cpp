//
// Created by Dmitry Petukhov on 28/03/2020.
//

#include <iostream>
#include <ncurses.h>
#include <ctime>

using namespace std;

int main()
{
    int currentYPos = 0;
    int currentXPos = 0;
    initscr();
    noecho();
    curs_set(false);
    nodelay(stdscr, true);
    keypad(stdscr, true);
    
    bool quit = false;
    
    int input; // int for arrow keys
    
    clock_t currentTime = clock(); // give us the current time in clockticks
    const int FPS = 60;
    
    while (!quit)
    {
        clock_t newTime = clock();
        clock_t dt = newTime - currentTime;
        
        if (dt > (CLOCKS_PER_SEC / FPS))  // ticks/sec / frame/sec -> t/f
        {
            currentTime = newTime;
            input = getch();
            if(input != 'q')
            {
                clear();
                
                if(input == KEY_DOWN)
                {
                    currentYPos++;
                }
                else if(input == KEY_UP)
                {
                    currentYPos--;
                }
                else if(input == KEY_LEFT)
                {
                    currentXPos--;
                }
                else if(input == KEY_RIGHT)
                {
                    currentXPos++;
                }
                
                mvprintw(currentYPos, currentXPos, "o");
                refresh();
                
            }
            else
            {
                quit = true;
            }
        }
    }
    
    endwin();
    
    return 0;
}