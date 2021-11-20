#pragma once
#include "BaseAccount.h"

class CreditAccount : public BaseAccount
{
private:
	int _spent = 0;
public:
	void Withdraw(float amount);
};