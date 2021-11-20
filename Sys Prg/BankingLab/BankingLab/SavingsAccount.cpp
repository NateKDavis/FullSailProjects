#include "SavingsAccount.h"

void SavingsAccount::Withdraw(float amount)
{
	if (_numOfWithdraws < 3)
	{
		BaseAccount::Withdraw(amount);
	}
}