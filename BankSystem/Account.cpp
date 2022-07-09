#include "Account.h"

Account::Account(const Customer& customer, const MyString& username, const MyString& password, const MyString& iban, double amaount)
{
	setCustomer(customer);
	setPassword(password);
	setUsername(username);
	setIban(iban);
	setAmaunt(amaount);
}

const Customer& Account::getCustomer() const
{
	return customer;
}
const MyString& Account::getIban() const
{
	return iban;
}
time_t Account::getDataOfCreation() const
{
	return dateOfCreation;
}
const MyString& Account::getUsername() const
{
	return username;
}
void Account::setCustomer(const Customer& customer)
{
	this->customer = customer;
}
void Account::setUsername(const MyString& username)
{
	this->username = username;
}
void Account::setPassword(const MyString& paassword)
{
	this->password = password;
}
void Account::setIban(const MyString& iban)
{
	this->iban = iban;
}
void Account::setAmaunt(double amount)
{
	this->amount = amount;
}
const Account::Type& Account::getTypeAccount() const
{
	return type;
}

bool Account::isCorrectPassword(const MyString& otherPass) const
{
	return password == otherPass;
}
