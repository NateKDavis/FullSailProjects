#include "CheckingAccount.h"

void CheckingAccount::Withdraw(float amount)
{
	BaseAccount::Withdraw(amount);

	if (_numOfWithdraws > 10)
	{
		_acountBalance = _acountBalance - 5;
	}
}