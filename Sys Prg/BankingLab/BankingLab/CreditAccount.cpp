#include "CreditAccount.h"

void CreditAccount::Withdraw(float amount)
{
	BaseAccount::Withdraw(amount);
	_spent = _spent + amount;
	if (_spent > 40)
	{
		_acountBalance = _acountBalance + 5000;
	}
}