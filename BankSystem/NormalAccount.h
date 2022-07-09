#pragma once
#include "Account.h"
#include "Customer.h"

class NormalAccount : public Account
{
public:

	NormalAccount() = default;
	NormalAccount(const Customer& customer, const MyString& username, const MyString& password, const MyString& iban, double amount);

	void deposit(int) override;
	bool withdraw(int) override;
	void display() override;
	double getBalance() const override;

	~NormalAccount() {}

	Account* clone() const override;

};