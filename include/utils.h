#pragma once

#include <iostream>
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>

#elif __linux__
    #include <unistd.h>
    #include <termios.h>

#endif

namespace utils{
    void ClearScreen();
    int GetDigit(int value);
    int GetDigit(int value, int digit);

    char getch();
}