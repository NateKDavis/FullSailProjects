#include <iostream>
using namespace std;

#pragma region MyRegion
int IsValidInt(int input, const char prompt[]);
void ClearInputBuffer();
void Formatting(const char prompt[]);
void ProgramOneDashOne();
void ProgramOneDashTwo();
void ProgramOneDashThree();
void ProgramOneDashFour();
void ProgramOneDashFive();
void ProgramOneDashSix();
void ProgramOneDashSeven();
void ProgramOneDashEight();
void ProgramOneDashNine();
void ProgramOneDashTen();
#pragma endregion

int main()
{
    ProgramOneDashOne();
    ProgramOneDashTwo();
    ProgramOneDashThree();
    ProgramOneDashFour();
    ProgramOneDashFive();
    ProgramOneDashSix();
    ProgramOneDashSeven();
    ProgramOneDashEight();
    ProgramOneDashNine();
    ProgramOneDashTen();
    system("pause");
}

// Will repeatedly ask given prompt until input is a valid Int (clears input buffer)
int IsValidInt(int input, const char prompt[])
{
    std::cout << prompt;

    while (!(std::cin >> input))
    {
        std::cout << prompt;
        std::cin >> input;
        ClearInputBuffer();
    }

    return input;
}

void ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore((300), '\n');   
}

// Spaces and prints a header with the given prompt
void Formatting(const char prompt[])
{
    std::cout << "-=-=-=-=  " << prompt << "  =-=-=-=-\n\n";
}

// Asks for the users initails and age. Verifies their age is an int
void ProgramOneDashOne()
{
    char initials[8];
    int age = 0;

    Formatting("Program 1-1");
    std::cout << "Please enter your initials (example: NKD): ";
    std::cin.get(initials, 8);
    ClearInputBuffer();
    age = IsValidInt(age, "Please enter your age (example: 24): ");
    age = age * 365;
    std::cout << initials << ", did you know you are at least " << age << " days old?\n\n";
}

// Asks the user for 5 numbers, then prints them out
void ProgramOneDashTwo()
{
    Formatting("Program 1-2");
    int numbers[5];
    int arraySize = (sizeof(numbers) / sizeof(numbers[0]));

    for (size_t i = 0; i < arraySize; i++)
    {
        numbers[i] = IsValidInt(numbers[i], "Please enter a number (example: 10): ");
    }

    std::cout << "You entered: ";

    for (size_t i = 0; i < arraySize; i++)
    {
        std::cout << numbers[i];
    }

    std::cout << "\n\n";
}

// Asks for 3 numbers to show the importance of order of operations
void ProgramOneDashThree()
{
    Formatting("Program 1-3");
    int a = 0;
    int b = 0;
    int c = 0;

    a = IsValidInt(a, "Please enter a number for A: ");
    b = IsValidInt(b, "Please enter a number for B: ");
    c = IsValidInt(a, "Please enter a number for C: ");

    cout << a << " + 1 * " << b << " + 2 - " << c << " = " << a + 1 * b + 2 - c << "\n";
    cout << "(" << a << " + 1) * (" << b << " + 2) - " << c << " = " << (a + 1) * (b + 2) - c << "\n\n";
}

// Displays variable types and their ranges
void ProgramOneDashFour()
{
    Formatting("Program 1-4");
    std::cout << "Type\t\tRange\n";
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    std::cout << "ushort\t\t0 to " << USHRT_MAX << "\n";
    std::cout << "short\t\t" << SHRT_MIN << " to " << USHRT_MAX << "\n";
    std::cout << "int\t\t" << INT_MIN << " to " << INT_MAX << "\n";
    std::cout << "uint\t\t0 to " << UINT_MAX << "\n";
    std::cout << "long\t\t" << LONG_MIN << " to " << LONG_MAX << "\n";
    std::cout << "ulong\t\t0 to " << ULONG_MAX << "\n\n";
}

// Asks for full name and displays a "fact"
void ProgramOneDashFive()
{
    char fullName[32];

    Formatting("Program 1-5");
    std::cout << "Please enter your full name: ";
    ClearInputBuffer();
    std::cin.getline(fullName, 32);    
    std::cout << "Hello " << fullName << ". Fun fact, 16% of satistics are made up on the spot.\n\n";
}

// Asks for an age and branches based on the answer
void ProgramOneDashSix()
{
    int age = 0;
    Formatting("Program 1-6");
    age = IsValidInt(age, "How old are you? ");

    if (age >= 16)
    {
        std::cout << "You are not scarred.. apparently... Sorry.\n\n";
    }
    else
    {
        age = 16 - age;
        std::cout << "Come back in " << age << " years!\n\n";
    }
}

// Asks for a number and says if it is even
void ProgramOneDashSeven()
{
    int num = 0;

    Formatting("Program 1-7");
    num = IsValidInt(num, "Enter an even number: ");

    if (num % 2 == 0)
    {
        std::cout << "Yay evenness!\n\n";
    }
    else
    {
        std::cout << "That's not even...\n\n";
    }
}

// Asks for a number, divdies 3 rand numbers by that number, says if they are evenly divisable
void ProgramOneDashEight()
{
    int divisor = 1;
    srand((unsigned)time(NULL));

    Formatting("Program 1-8");
    divisor = IsValidInt(divisor, "Please enter a number to divde by: ");

    for (size_t i = 0; i < 3; i++)
    {
        int num = rand();
        std::cout << num << " divided by " << divisor << " is evenly divisable: ";

        if (num % divisor == 0)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }

    std::cout << "\n";
}

// Asks for number and gives the corresponding popsicle
void ProgramOneDashNine()
{
    enum Popsicles
    {
        Red = 1,
        Green,
        Blue,
        Orange = 13
    };
    Popsicles selected = Popsicles::Red;

    Formatting("Program 1-9");
    selected = (Popsicles)IsValidInt(selected, "What color Popsicle do you want?\n1) Red\n2) Green\n3) Blue\n13) Orange\n");

    switch (selected)
    {
    case Red:
        std::cout << "One red popsicle for you.\n\n";
        break;
    case Green:
        std::cout << "One Green popsicle for you.\n\n";
        break;
    case Blue:
        std::cout << "One Blue popsicle for you.\n\n";
        break;
    case Orange:
        std::cout << "One Orange popsicle for you.\n\n";
        break;
    default:
        std::cout << "One nonexsistant popsicle for you.\n\n";
        break;
    }
}

// Provides a pseudo-random number of enemies based on selected diffculty
void ProgramOneDashTen()
{
    srand((unsigned)time(NULL));
    int num = rand() % 10;

    enum difficutlyLevel
    {
        Easy = 1,
        Medium,
        Hard
    };
    difficutlyLevel selected = difficutlyLevel::Easy;

    Formatting("Program 1-10");
    selected = (difficutlyLevel)IsValidInt(selected, "Difficulty Levels\n1) Easy\n2) Medium\n3) Hard\nWhat level? ");

    switch (selected)
    {
    case Easy:
        std::cout << "You encountered " << num << " enemies!\n\n";
        break;
    case Medium:
        std::cout << "You encountered " << num * 2 << " enemies!\n\n";
        break;
    case Hard:
        std::cout << "You encountered " << num * 3 << " enemies!\n\n";
        break;
    default:
        std::cout << "You encountered no enemies!\n\n";
        break;
    }
}
