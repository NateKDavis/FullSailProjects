#pragma once
class BaseAccount
{
protected:
	float _acountBalance = 0;
	int _numOfWithdraws = 0;
public:
	void Withdraw(float amount);
	void Deposit(float amount);
	float GetBalance() const;
	int GetNumWithdraw() const;
};