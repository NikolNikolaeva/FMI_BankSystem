#include "PrivilegeAccount.h"
#include <iostream>
#include <ctime>
#pragma warning(disable:4996)


PrivilegeAccount::PrivilegeAccount( const Customer& customer, const MyString& username, const MyString& password, const MyString& iban, double amount, double overdraft) :Account(customer,username, password, iban, amount)
{
	setOverdraft(overdraft);
	type = Type::Privilege;

}

void PrivilegeAccount::deposit(int sum)
{
	amount += sum;
}

bool PrivilegeAccount::withdraw(int sum)
{
	if (sum >= (amount + overdraft))
		return false;

	amount -= sum;
	overdraft = 0;
	return true;
}

void PrivilegeAccount::display()
{
	tm* now = localtime(&dateOfCreation);
	std::cout <<"Date of creation: "<< (now->tm_year + 1900) << "." << (now->tm_mon + 1) << "." << now->tm_mday << ", type: Privilege, IBAN: " << getIban() << ", customer ID: " << customer.getId() << ", balance: " << getBalance() << ", overdraft " << getOverdraft() << std::endl;
}
double PrivilegeAccount::getBalance() const
{
	return amount;
}
void PrivilegeAccount::setOverdraft(double overdraft)
{
	this->overdraft = overdraft;
}
double PrivilegeAccount::getOverdraft() const
{
	return overdraft;
}

Account* PrivilegeAccount::clone() const
{
	Account* copy = new PrivilegeAccount(*this);
	return copy;
}

