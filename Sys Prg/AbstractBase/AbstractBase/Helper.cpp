#include <iostream>
#include "Helper.h"

// Will repeatedly ask given prompt until input is a valid Int inside of the given range
int GetValidatedInt(const char* strMessage, int nMinimumRange, int nMaximumRange)
{
    int input;
    std::cout << strMessage;

    while (true)
    {
        std::cin >> input;
        
        if (nMinimumRange == 0 && nMaximumRange == 0)
        {
            nMinimumRange = INT_MIN;
            nMaximumRange = INT_MAX;
        }

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

// Creates a title -=-=-=-= your input =-=-=-=- then goes two lines down
void Header(const char header[32])
{
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=  " << header << "  =-=-=-=-=-=-=-=-=-=-=-\n" << std::endl;
}

// Ends the current line, pauses for input, then clears the screen
void Footer()
{
    std::cout << std::endl;
    system("pause");
    system("cls");
}

// Clears input buffer and ignore until next \n
void ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore((UINT_MAX), '\n');
}

// Creates a random number between given min and max. min can default to 0. max is not inclusive
int RandomNumber(int max)
{
    srand((unsigned)time(NULL));
    return rand() % max + 1;
}

// Copies a char array into another
void CopyString(const char* source, char*& destination)
{
    delete[] destination;
    size_t len = strlen(source) + 1;
    destination = new char[len];
    strcpy_s(destination, len, source);
}

// Will repeatedly ask given prompt until input is a valid Int inside of the given range
float GetValidatedFloat(const char* strMessage, float nMinimumRange, float nMaximumRange)
{
    float input;
    std::cout << strMessage;

    while (true)
    {
        std::cin >> input;

        if (nMinimumRange == 0 && nMaximumRange == 0)
        {
            nMinimumRange = FLT_MIN;
            nMaximumRange = FLT_MAX;
        }

        if (std::cin.fail() >> (int)input || input < nMinimumRange || input > nMaximumRange)
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

void promptForText(const char* prompt, char*& text)
{
    char buffer[5000];
    std::cout << prompt;
    std::cin.getline(buffer, 5000);

    int length = strlen(buffer) + 1;

    text = new char[length];
    strcpy_s(text, length, buffer);
}