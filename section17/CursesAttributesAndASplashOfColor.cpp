//
// Created by Dmitry Petukhov on 28/03/2020.
//

#include <iostream>
#include <ncurses.h>
#include <string>

using namespace std;

int main()
{
    initscr();
    noecho();
    curs_set(false);
    
    string aString = "Hello Everyone";
    
    /*
     * A_NORMAL     Normal display (no highlight)
     * A_STANDOUT   Bext highlightning mode of the terminal.
     * A_UNDERLINE  Underlining
     * A_REVERSE    Reverse video
     * A_BLINK      Blinking
     * A_DIM        Half bright
     * A_BOLD       Extra bright of bold
     * A_PROTECT    Protected mode
     * A_INVIS      Invisible or blank mode
     * A_ALTCHARSET Alternate character set
     * A_CHARTEXT   Bit-mask to extract a character
     */
    
    /*
     * COLOR_BLACK   0
     * COLOR_RED     1
     * COLOR_GREEN   2
     * COLOR_YELLOW  3
     * COLOR_BLUE    4
     * COLOR_MAGENTA 5
     * COLOR_CYAN    6
     * COLOR_WHITE   7
     */
    
    if(!has_colors())
    {
        endwin();
        cout << "Your console doesn't support colors! Too bad... " << endl;
        return 0;
    }
    
    start_color();
    
    init_pair(1, COLOR_RED, COLOR_BLACK);
    
    attron(A_STANDOUT);
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    
    mvprintw(LINES/2, COLS/2 - aString.length()/2, aString.c_str());
    
    getch();
    
    endwin();
//    while (true)
//        main();
    return 0;
}