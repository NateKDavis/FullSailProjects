#include <iostream>
#include <fstream>
#include "BaseAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Helper.h"

int main()
{
	CheckingAccount* checking = new CheckingAccount;
	SavingsAccount* saving = new SavingsAccount;
	CreditAccount* credit = new CreditAccount;

	std::ifstream fin;
	fin.open("AccountBalances.txt");

	if (fin.is_open())
	{
		float temp;
		fin >> temp;
		fin.ignore(INT_MAX, '\n');
		checking->Deposit(temp);

		fin >> temp;
		fin.ignore(INT_MAX, '\n');
		saving->Deposit(temp);

		fin >> temp;
		fin.ignore(INT_MAX, '\n');
		credit->Deposit(temp);

		fin.close();
	}
	else
	{
		checking->Deposit(10);
		saving->Deposit(20);
		credit->Deposit(30);
	}

	bool isRunning = true;

	while (isRunning)
	{
		int action = 0;
		float amount = 0;

		Helper::Header("  CMD Banking  ");
		int accountSelected = Helper::GetValidatedInt("Which account would you like to access? (Enter the number)\n1) Checking\n2) Savings\n3) Credit\n4) Exit\n", 1, 4);
		system("cls");

		switch (accountSelected)
		{
		case 1:
			Helper::Header("  Checking Account  ");
			std::cout << "Balance: " << checking->GetBalance() << std::endl;
			action = Helper::GetValidatedInt("What would you like to do?\n1) Deposit\n2) Withdraw\n3) Go Back\n", 1, 3);

			switch (action)
			{
			case 1:
				amount = Helper::GetValidatedFloat("Amount to deposit: ");
				checking->Deposit(amount);
				system("cls");
				std::cout << "New balance: " << checking->GetBalance() << std::endl;
				Helper::Footer();
				break;

			case 2:
				amount = Helper::GetValidatedFloat("Amount to withdraw: ");
				checking->Withdraw(amount);
				system("cls");
				std::cout << "New balance: " << checking->GetBalance() << std::endl;
				Helper::Footer();
				break;
			case 3:
				system("cls");
				break;
			}

			break;

		case 2:
			Helper::Header("  Savings Account  ");
			std::cout << "Balance: " << saving->GetBalance() << std::endl;
			action = Helper::GetValidatedInt("What would you like to do?\n1) Deposit\n2) Withdraw\n3) Go Back\n", 1, 3);

			switch (action)
			{
			case 1:
				amount = Helper::GetValidatedFloat("Amount to deposit: ");
				saving->Deposit(amount);
				system("cls");
				std::cout << "New balance: " << saving->GetBalance() << std::endl;
				Helper::Footer();
				break;

			case 2:
				amount = Helper::GetValidatedFloat("Amount to withdraw: ");
				saving->Withdraw(amount);
				system("cls");
				std::cout << "New balance: " << saving->GetBalance() << std::endl;
				Helper::Footer();
				break;
			case 3:
				system("cls");
				break;
			}

			break;

		case 3:
			Helper::Header("  Credit Account  ");
			std::cout << "Balance: " << credit->GetBalance() << std::endl;
			action = Helper::GetValidatedInt("What would you like to do?\n1) Deposit\n2) Withdraw\n3) Go Back\n", 1, 3);

			switch (action)
			{
			case 1:
				amount = Helper::GetValidatedFloat("Amount to deposit: ");
				credit->Deposit(amount);
				system("cls");
				std::cout << "New balance: " << credit->GetBalance() << std::endl;
				Helper::Footer();
				break;

			case 2:
				amount = Helper::GetValidatedFloat("Amount to withdraw: ");
				credit->Withdraw(amount);
				system("cls");
				std::cout << "New balance: " << credit->GetBalance() << std::endl;
				Helper::Footer();
				break;
			case 3:
				system("cls");
				break;
			}
		case 4:
			system("cls");
			isRunning = false;
			break;
			
		}
	}

	Helper::Footer();
	std::ofstream fout;
	fout.open("AccountBalances.txt", 'w');

	if (fout.is_open())
	{
		fout << checking->GetBalance() << std::endl;
		fout << saving->GetBalance() << std::endl;
		fout << credit->GetBalance() << std::endl;

		fout.close();
	}

	delete checking;
	delete saving;
	delete credit;
}