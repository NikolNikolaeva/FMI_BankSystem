#pragma once
#include "Account.h"

class PrivilegeAccount : public Account
{
private:

	int overdraft;

public:

	PrivilegeAccount(const Customer& customer, const MyString& username, const MyString& password, const MyString& iban, double amaount, double overdraft);

	void deposit(int sum) override;
	bool withdraw(int sum) override;
	void display() override;
	double getBalance() const override;

	double getOverdraft() const;
	void setOverdraft(double overdraft);

	~PrivilegeAccount() {}

	Account* clone() const override;
};