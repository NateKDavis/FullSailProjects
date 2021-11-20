// Lab 5.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <random>

int main()
{
    std::cout << "any message you want to print to the console window.\n";

    bool isValid = true;
    int intNum = 0;
    float floatNum = 0;
    double doubleNum = 0;
    char letter = 'A';

    std::cout << isValid << " " << sizeof(isValid) << "\n";
    std::cout << intNum << " " << sizeof(intNum) << "\n";
    std::cout << floatNum << " " << sizeof(floatNum) << "\n";
    std::cout << doubleNum << " " << sizeof(doubleNum) << "\n";
    std::cout << letter << " " << sizeof(letter) << "\n";

    float floatArray[4]{ 1, 1.5, 2, 2.5 };

    for(int i = 0; i < 4; i++)
    {
        std::cout << floatArray[i] << " ";
    }

    char charArray[] = "Batman";

    std::cout << "\n";

    for (int i = 0; i < 6; i++)
    {
        std::cout << charArray[i];
    }

    std::cout << "\n";

    for (size_t i = 0; i < 101; i++)
    {
        if (i % 2 == 0)
        {
            std::cout << i << " ";
        }        
    }

    std::cout << "\n";

    int counter = 0;

    while (counter < 100)
    {
        counter++;
    }

    std::cout << counter << "\n";

    int counterTwo = 0;

    do
    {
        counterTwo++;
    } while (counterTwo < 100);

    std::cout << counterTwo << "\n";

    srand((unsigned)time(NULL));

    for (size_t i = 0; i < 10; i++)
    {
        int randNum = rand() % 101;

        if (randNum <= 69)
        {
            letter = 'F';
        }
        else if (randNum <= 72)
        {
            letter = 'D';
        }
        else if (randNum <= 79)
        {
            letter = 'C';
        }
        else if (randNum <= 89)
        {
            letter = 'B';
        }
        else
        {
            letter = 'A';
        }

        std::cout << randNum << " " << letter << "\n";
    }

    for (size_t i = 0; i < 10; i++)
    {
        int randNumTwo = rand() % 6;

        switch (randNumTwo)
        {
        case 0 :
            std::cout << "The Bat\n";
            break;
        case 1:
            std::cout << "Batman\n";
            break;
        case 2:
            std::cout << "Bats\n";
            break;
        case 3:
            std::cout << "The Dark Kinght\n";
            break;
        case 4:
            std::cout << "Nightwing\n";
            break;
        case 5:
            std::cout << "Bruce\n";
            break;
        }
    }

    int randNumThree = rand() % 6;
    int superpower = 0;

    enum Superpowers
    {
        Strength,
        Speed,
        Sight,
        Flight,
        Indestructible
    };

    switch()


    std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
