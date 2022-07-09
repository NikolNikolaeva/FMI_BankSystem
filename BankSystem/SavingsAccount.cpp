#include "SavingsAccount.h"
#include <iostream>
#include <ctime>
#pragma warning(disable:4996)

SavingsAccount::SavingsAccount(const Customer& customer, const MyString& username, const  MyString& password, const MyString& iban, double amount, double interestRate)
	:Account(customer, username, password, iban, amount)
{
	setInterestRate(interestRate);
	type = Type::Privilege;
}

void SavingsAccount::deposit(int sum)
{
	amount += sum;
}

bool SavingsAccount::withdraw(int sum)
{
	return false;
}

void SavingsAccount::display()
{
	std::tm* now = std::localtime(&dateOfCreation);
	std::cout << "Date of creation: " << (now->tm_year + 1900) << "." << (now->tm_mon + 1) << "." << now->tm_mday << ", type: Savings, IBAN: " << getIban() << ", customer ID: " << customer.getId() << ", balance: " << getBalance() << ", interestRate: " << getInterestRate() << std::endl;
}
double SavingsAccount::getBalance() const
{
	return amount;
}

double SavingsAccount::getInterestRate() const
{
	return interestRate;
}

void SavingsAccount::setInterestRate(double interestRate)
{
	this->interestRate = interestRate;
}

Account* SavingsAccount::clone() const
{
	Account* copy = new SavingsAccount(*this);
	return copy;
}

