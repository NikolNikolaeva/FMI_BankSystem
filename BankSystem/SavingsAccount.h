#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
private:

	double interestRate;

public:

	SavingsAccount(const Customer& customer, const MyString& username, const MyString& password, const MyString& iban, double amaount, double interestRate = 0);

	void deposit(int sum) override;
	bool withdraw(int sum) override;
	void display() override;
	double getBalance() const override;

	double getInterestRate() const;
	void setInterestRate(double interestRate);

	~SavingsAccount() = default;

	Account* clone() const override;
};