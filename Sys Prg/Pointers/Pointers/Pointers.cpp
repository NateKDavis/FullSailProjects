#include <iostream>

enum EnumColorDefinition
{
    Red = 1,
    Blue,
    Green,
    Yellow,
    Purple
};

//Sets up what a car is
struct Car {
    char make[32];
    char model[32];
    int year;
    int mileage;
    EnumColorDefinition color;
};

Car cars[3];

#pragma region Declarations
void Header(const char title[32]);
void Footer();
void ClearInputBuffer();
int IsValidInt(int input, const char prompt[]);
void PrintValueAndAddress(int num, int* pointer);
void RepaintCar(Car* ptrCar, EnumColorDefinition newcolor);
void GetCarDetails();
void PrintCarDetails();
void PrintCar(Car givenCar);
void PrintCar(Car* givenCarPointer);
void RepaintProgram();
void AddMileage(Car* ptrCar, int milestoadd);
void MileageProgram();
void ProgramOne();
void ProgramTwo();
void ProgramThree();
#pragma endregion

int main()
{
    ProgramOne();
    ProgramTwo();
    ProgramThree();
    RepaintProgram();
    MileageProgram();
}

//Creates a title -=-=-=-= your input =-=-=-=- then goes two lines down
void Header(const char title[32])
{
    std::cout << "-=-=-=-=-=-=-=-=  " << title << "  =-=-=-=-=-=-=-=-\n" << std::endl;
}

//ends the current line, pauses for input, then clears the screen
void Footer()
{
    std::cout << std::endl;
    system("pause");
    system("cls");
}

void ClearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore((300), '\n');
}

// Will repeatedly ask given prompt until input is a valid Int (also clears input buffer)
int IsValidInt(int input, const char prompt[])
{
    std::cout << prompt;

    while (!(std::cin >> input))
    {
        std::cout << prompt;
        std::cin >> input;
        ClearInputBuffer();
    }
    ClearInputBuffer();
    return input;
}

//prints given num and pointer
void PrintValueAndAddress(int num, int* pointer)
{
    std::cout << "Number: " << num << "\tPointer: " << pointer << std::endl;
}

//changes the color of a car
void RepaintCar(Car* ptrCar, EnumColorDefinition newcolor)
{
    ptrCar->color = newcolor;
}

//Gets make, model, year, mileage, and color for the cars
void GetCarDetails()
{
    for (int i = 0; i < 3; i++)
    {
        Header("Program Three - Making Cars");

        std::cout << "Car " << i + 1 << std::endl;
        std::cout << "Make: ";                                                      //For each car
        std::cin.getline(cars[i].make, 32);                                         //Gets make

        std::cout << "Model: ";
        std::cin.getline(cars[i].model, 32);                                        //Gets model

        cars[i].year = IsValidInt(cars[i].year, "Year: ");                          //Gets year

        cars[i].mileage = IsValidInt(cars[i].mileage, "Mileage: ");                 //Gets mileage

        system("cls");
        Header("Program Three - Making Cars");
        std::cout << "Car " << i + 1 << std::endl;
        std::cout << "1) Red\n2) Blue\n3) Green\n4) Yellow\n5) Purple\n" << std::endl;
        cars[i].color = (EnumColorDefinition)IsValidInt(cars[i].color, "Color: ");  //Gets the color

        system("cls");
    }
}

//Prints Car Details via direct acces and via pointers
void PrintCarDetails()
{
    Header("Your Cars - Direct access");

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Car " << i + 1;
        PrintCar(cars[i]);
    }
    
    std::cout << std::endl;

    Header("Your Cars - Pointer access");

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Car " << i + 1;
        PrintCar(&cars[i]);
    }
}

//directly access data to print out the given car's make, model, year, mileage, and color
void PrintCar(Car givenCar)
{
    std::cout << ") Year: " << givenCar.year << "   Color : ";

    switch (givenCar.color)
    {
    case Red:
        std::cout << "Red   ";
        break;
    case Blue:
        std::cout << "Blue  ";
        break;
    case Green:
        std::cout << "Green ";
        break;
    case Yellow:
        std::cout << "Yellow";
        break;
    case Purple:
        std::cout << "Purple";
        break;
    }

    std::cout
        << "   Make : " << givenCar.make
        << "   Model: " << givenCar.model
        << "   Mileage: " << givenCar.mileage
        << std::endl;
}

//access data via pointers to print out the given car's make, model, year, mileage, and color
void PrintCar(Car* givenCarPointer)
{
    std::cout << ") Year: " << (*givenCarPointer).year << "   Color : ";

    switch ((*givenCarPointer).color)
    {
    case Red:
        std::cout << "Red   ";
        break;
    case Blue:
        std::cout << "Blue  ";
        break;
    case Green:
        std::cout << "Green ";
        break;
    case Yellow:
        std::cout << "Yellow";
        break;
    case Purple:
        std::cout << "Purple";
        break;
    }

    std::cout
        << "   Make : " << (*givenCarPointer).make
        << "   Model: " << (*givenCarPointer).model
        << "   Mileage: " << (*givenCarPointer).mileage
        << std::endl;
}

//Changes the selected car to purple
void RepaintProgram()
{
    Header("Repainting");

    int repaintQuestion = 0;
    repaintQuestion = IsValidInt(repaintQuestion, "Please select a car to repaint: ") - 1;

    RepaintCar(&cars[repaintQuestion], Purple);

    PrintCarDetails();
    Footer();
}

//adds miles to the given car
void AddMileage(Car* ptrCar, int milestoadd)
{
    ptrCar->mileage = ptrCar->mileage + milestoadd;
}

//asks what car to add miles to and how many miles
void MileageProgram()
{
    Header("Mileage");

    int mileageQuestion = 0;
    mileageQuestion = IsValidInt(mileageQuestion, "Please select a car to add mileage to: ") - 1;

    int mileageToAdd = 0;
    mileageToAdd = IsValidInt(mileageToAdd, "How many miles to add: ");

    AddMileage(&cars[mileageQuestion], mileageToAdd);

    PrintCarDetails();
    Footer();
}

//Create int[15] and fills it with rand nums, then prints the value and address for each
void ProgramOne()
{
    Header("Program One");

    srand(time(NULL));
    int nums[15];    

    for (size_t i = 0; i < 15; i++)
    {
        nums[i] = rand();
        std::cout << i << ")\tValue: " << nums[i] << "\tAddress: " << &nums[i] << std::endl;
    }

    Footer();
}

//does what program one does but uses function
void ProgramTwo()
{
    Header("Program Two");

    int nums[15];

    for (int i = 0; i < 15; i++)
    {
        nums[i] = rand();
        PrintValueAndAddress(nums[i], &nums[i]);
    }
    
    Footer();
}

//Asks for car details, then prints out the car infos
void ProgramThree()
{
    GetCarDetails();
    PrintCarDetails();
    Footer();
}