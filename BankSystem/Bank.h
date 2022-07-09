#pragma once 
#include "MyString.h"
#include "T-vector.hpp"
#include "Customer.h"
#include "Account.h"
#include "Pair.hpp"
#include "AccountsCollection.h"


class Bank
{
private:

	MyString name;
	MyString address;
	Vector<Customer> customerList;
	AccountsCollection accounts;
	Vector<MyString> log;
	double overdraft;
	double interestRate;

	void setName(const MyString& name);
	void setAddress(const MyString& address);

	void setOverdraft(double);
	void setInterestRate(double);

public:

	Bank() = default;

	const MyString& getName() const;
	const MyString& getAddress() const;
	const Vector<Customer>& getCustomersList() const;

	void addCustomer(const Customer& customer);
	void deleteCustomer(size_t id);
	void addAccount(size_t id, double& overdtaft, double& interestRate);
	void deleteAccount(MyString& Iban, MyString);
	void listCustomers() const;
	void listAccounts() const;
	void listCustomerAccount(size_t id) const;
	void exportLog();
	void transfer(const MyString& fromIban, const MyString& toIban, double amount, const MyString& pass);
	void display() const;

	void interface();
};