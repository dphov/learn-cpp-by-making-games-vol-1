//
// Created by Dmitry Petukhov on 28/03/2020.
//

#include <iostream>
#include <string>
#include "CursesUtils.h"

using namespace std;

int main()
{
    InitializeCurses(false);
    
    string aString = "Hello Everyone";
    
    mvprintw(10, 10, aString.c_str());
    
    GetChar();
    
    ShutdownCurses();
    
    return 0;
}