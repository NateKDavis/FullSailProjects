#include <iostream>
#include <string>
#include "Helper.h"

// Will repeatedly ask given prompt until input is a valid Int inside of the given range
int Helper::GetValidatedInt(const char* strMessage, int nMinimumRange, int nMaximumRange)
{
    int input;
    std::cout << strMessage;

    while (true)
    {
        std::cin >> input;

        if (std::cin.fail() >> input || input < nMinimumRange || input > nMaximumRange)
        {            
            std::cout << "Input was not a number between " << nMinimumRange << " and " << nMaximumRange << "." << std::endl;
            std::cout << strMessage;
            ClearInputBuffer();
            continue;
        }
        
        std::cin.ignore((UINT_MAX), '\n');
        break;
    }
    return input;
}

//Creates a title -=-=-=-= your input =-=-=-=- then goes two lines down
void Helper::Header(const char header[32])
{
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=  " << header << "  =-=-=-=-=-=-=-=-=-=-=-\n" << std::endl;
}

//ends the current line, pauses for input, then clears the screen
void Helper::Footer()
{
    std::cout << std::endl;
    system("pause");
    system("cls");
}

//clears input buffer and ignore until next \n
void Helper::ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore((UINT_MAX), '\n');
}

//Creates a random number between given min and max. min can default to 0. max is not inclusive
int Helper::RandomNumber(int max)
{
    srand((unsigned)time(NULL));
    return rand() % max + 1;
}
