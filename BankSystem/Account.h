#pragma once
#include "Customer.h"
#include "MyString.h"
#include <ctime>

class Account
{
protected:

	Customer customer;
	MyString username;
	MyString password;
	MyString iban;
	double amount;
	time_t dateOfCreation = time(NULL);
	enum Type
	{
		Normal,
		Privilege,
		Savings,
		Unknown
	}type;

	void setCustomer(const Customer& customer);
	void setPassword(const MyString& paassword);
	void setUsername(const MyString& username);
	void setIban(const MyString& iban);
	void setAmaunt(double amaunt);


public:

	Account() = default;
	Account(const Customer& customer,const MyString& username, const MyString& password, const MyString& iban, double amaount = 0);

	virtual void deposit(int) = 0;
	virtual bool withdraw(int) = 0;
	virtual void display() = 0;
	virtual double getBalance() const = 0;

	virtual ~Account() {}

	bool isCorrectPassword(const MyString& otherPass) const;
const MyString& getUsername() const;
	const Customer& getCustomer() const;
	const MyString& getIban() const;
	const Type& getTypeAccount() const;
	time_t getDataOfCreation() const;

	virtual Account* clone() const = 0;
};