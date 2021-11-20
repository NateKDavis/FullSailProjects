#include "BaseAccount.h"

void BaseAccount::Withdraw(float amount)
{
	_acountBalance = _acountBalance - amount;
	_numOfWithdraws++;
}

void BaseAccount::Deposit(float amount)
{
	_acountBalance = _acountBalance + amount;
}

float BaseAccount::GetBalance() const
{
	return _acountBalance;
}

int BaseAccount::GetNumWithdraw() const
{
	return _numOfWithdraws;
}