#include <iostream>

#pragma region Declarations
void TurnOn(int bit);
void TurnOff(int bit);
void Toggle(int bit);
void Negate();
void LeftShift();
void RightShift();
void PrintBinaryNumber(unsigned int num, int size);
int IsValidInt(int input, const char prompt[]);
void ClearInputBuffer();
void Header();
#pragma endregion

unsigned int bitField;

int main()
{
	int userInput = 0;
	bool run = true;
	int bitToAdjust = 0;

	Header();
	std::cout << "Please enter a number between " << 0 << " and " << UINT_MAX << ". Then press enter." << std::endl;
	bitField = IsValidInt(bitField, "Number: ");
	system("cls");	

	while (run)
	{
		Header();
		std::cout << "What bit manipulation would you like to do?\n1) TurnOn\n2) TurnOff\n3) Toggle\n4) Negate\n5) Left Shift\n6) Right Shift\n7) Exit" << std::endl;

		userInput = IsValidInt(userInput, "Selection: ");
		system("cls");

		switch (userInput)
		{
		case 1:
			Header();
			std::cout << "What bit would you like to turn on?" << std::endl;
			bitToAdjust = IsValidInt(bitToAdjust, "Bit: ");
			TurnOn(1 << bitToAdjust - 1);
			system("cls");
			break;
		case 2:
			Header();
			std::cout << "What bit would you like to turn off?" << std::endl;
			bitToAdjust = IsValidInt(bitToAdjust, "Bit: ");
			TurnOff(1 << bitToAdjust - 1);
			system("cls");
			break;
		case 3:
			Header();
			std::cout << "What bit would you like to toggle?" << std::endl;
			bitToAdjust = IsValidInt(bitToAdjust, "Bit: ");
			Toggle(1 << bitToAdjust - 1);
			system("cls");
			break;
		case 4:
			Header();
			Negate();
			system("cls");
			break;
		case 5:
			Header();
			LeftShift();
			system("cls");
			break;
		case 6:
			Header();
			RightShift();
			
			system("cls");
			break;
		case 7:
			run = false;
			break;
		}
	}
	system("pause");
}

void TurnOn(int bit)
{
	bitField = bitField | bit;
}

void TurnOff(int bit)
{
	bitField = bitField & (~bit);
}

void Toggle(int bit)
{
	bitField = bitField ^ bit;
}

void Negate()
{
	bitField = ~bitField;
}

void LeftShift()
{
	bitField = bitField << 1;
}

void RightShift()
{
	bitField = bitField >> 1;
}

void PrintBinaryNumber(unsigned int num, int size)
{
	char* text = new char[size + 1];
	text[size] = '\0';

	for (int i = size - 1; i >= 0; i--)
	{
		if (num % 2 == 0)
		{
			text[i] = '0';
		}
		else
		{
			text[i] = '1';
		}
		num = num / 2;
	}

	for (int i = 0; i < size; i++)
	{
		if (i % 4 == 0)
		{
			std::cout << " ";
		}
		std::cout << text[i];
	}
	std::cout << std::endl;
	delete[] text;
}

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

void Header()
{
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=  Bit Manipulation Lab  =-=-=-=-=-=-=-=-=-=-=-=-\n" << std::endl;
	std::cout << "Bitfield: " << bitField << std::endl;
	std::cout << "Your number in bits: ";
	PrintBinaryNumber(bitField, 32);
	std::cout << std::endl;
}