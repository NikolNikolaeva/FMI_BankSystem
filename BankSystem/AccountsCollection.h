#pragma once 
#include "Account.h"
#include "NormalAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#include "T-vector.hpp"
#include <iostream>

class AccountsCollection
{
private:

	Account** accounts;
	size_t accountsCount;
	size_t capacity;

	void free();
	void copyFrom(const AccountsCollection& other);
	void resize();

	bool addAccount(const Account* account);

public:

	AccountsCollection();
	AccountsCollection(const AccountsCollection& other);
	AccountsCollection& operator=(const AccountsCollection& other);
	~AccountsCollection();

	bool addNormalAccount(const Customer& customer, const MyString& username, const MyString& password, const MyString& iban, double amaount);
	bool addPrivilegeAccount(const Customer& customer, const MyString& username, const MyString& password, const MyString& iban, double amaount, double);
	bool addSavingsAccount(const Customer& customer, const MyString& username, const MyString& password, const MyString& iban, double amaount,double);

	bool deleteAccount(MyString& Iban,MyString& pass);

	size_t getAccountaCount() const;

	bool isValidAccount(const MyString&) const;

	void printInfoAccounts() const;

	void printAccountsForOneCustomer(size_t id) const;

	bool withdraw(const MyString& iban, double sum,const MyString& pass);

	bool depozit(const MyString& iban, double sum, const MyString& pass);

	bool transfer(const MyString& fromIban, const MyString& toIban, double amount, const MyString& pass);

};