#include "NormalAccount.h"
#include <iostream>
#include <ctime>
#pragma warning(disable:4996)

NormalAccount::NormalAccount(const Customer& customer, const MyString& username, const MyString& password, const MyString& iban, double amount) :Account(customer,username, password, iban, amount)
{
	type = Type::Normal;
}

void NormalAccount::deposit(int sum)
{
	amount += sum;
}

bool NormalAccount::withdraw(int sum)
{
	if (sum > amount)
		return false;

	amount -= sum;
	return true;
}

void NormalAccount::display()
{
	tm* now = localtime(&dateOfCreation);
	std::cout <<"Date of creation: "<< (now->tm_year + 1900) << "." << (now->tm_mon + 1) << "." << now->tm_mday << ", type: Normal, IBAN: " << getIban() << ", customer ID: " << customer.getId() << ", balance: " << getBalance() << std::endl;
}
double NormalAccount::getBalance() const
{
	return amount;
}

Account* NormalAccount::clone() const
{
	Account* copy = new NormalAccount(*this);
	return copy;
}



