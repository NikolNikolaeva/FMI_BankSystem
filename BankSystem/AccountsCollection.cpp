#include "AccountsCollection.h"


void AccountsCollection::free()
{
	for (size_t i = 0; i < accountsCount; i++)
	{
		delete accounts[i];
	}
	delete[] accounts;
}

void AccountsCollection::copyFrom(const AccountsCollection& other)
{
	accounts = new Account * [other.accountsCount];
	accountsCount = other.accountsCount;
	capacity = other.capacity;

	for (size_t i = 0; i < accountsCount; i++)
	{
		accounts[i] = other.accounts[i]->clone();
	}
}

void AccountsCollection::resize()
{
	Account** newCollection = new Account * [capacity *= 2];
	for (size_t i = 0; i < accountsCount; i++)
	{
		newCollection[i] = accounts[i];
	}
	delete[] accounts;
	accounts = newCollection;
}

bool AccountsCollection::addAccount(const Account* account)
{
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (accounts[i]->getIban() == account->getIban())
		{
			return false;
		}
	}

	if (accountsCount == capacity)
		resize();

	accounts[accountsCount++] = account->clone();
	return true;
}

AccountsCollection::AccountsCollection()
{
	capacity = 8;
	accountsCount = 0;
	accounts = new Account * [capacity];
}

AccountsCollection::AccountsCollection(const AccountsCollection& other)
{
	copyFrom(other);
}
AccountsCollection& AccountsCollection::operator=(const AccountsCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
AccountsCollection::~AccountsCollection()
{
	free();
}

bool AccountsCollection::addNormalAccount(const Customer& customer, const MyString& username, const  MyString& password, const MyString& iban, double amaount)
{
	NormalAccount* newAccount = new NormalAccount(customer, username, password, iban, amaount);
	if (addAccount(newAccount))
		return true;
	return false;
}
bool AccountsCollection::addPrivilegeAccount(const Customer& customer, const MyString& username, const MyString& password, const MyString& iban, double amaount, double overdraft)
{
	PrivilegeAccount* newAccount = new PrivilegeAccount(customer, username, password, iban, amaount, overdraft);
	if (addAccount(newAccount))
		return true;
	return false;
}
bool AccountsCollection::addSavingsAccount(const Customer& customer, const MyString& username, const MyString& password, const MyString& iban, double amount, double interestRate)
{
	SavingsAccount* newAccount = new SavingsAccount(customer,username, password, iban, amount, interestRate);
	if (addAccount(newAccount))
		return true;
	return false;
}

bool AccountsCollection::deleteAccount(MyString& username, MyString& pass)
{
	if (accountsCount == 0)
		return false;

	size_t index = 0;
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (accounts[i]->getUsername() == username)
		{
			index = i;
			break;
		}
	}

	if (accounts[index]->isCorrectPassword(pass))
	{

		for (size_t i = index; i < accountsCount; i++)
		{
			accounts[index] = accounts[i + 1];
		}

		delete accounts[accountsCount];
		accountsCount--;
		return true;
	}
	else
	{
		std::cout << "	Invalid password" << std::endl;
		return false;
	}

}

bool AccountsCollection::isValidAccount(const MyString& iban) const
{
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (iban == accounts[i]->getIban())
			return true;
	}
	return false;
}

size_t AccountsCollection::getAccountaCount() const
{
	return accountsCount;
}

void AccountsCollection::printInfoAccounts() const
{
	for (size_t i = 0; i < accountsCount; i++)
	{
		std::cout << "\t" << i + 1 << ". ";
		accounts[i]->display();
	}
}

void AccountsCollection::printAccountsForOneCustomer(size_t id) const
{
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (accounts[i]->getCustomer().getId() == id)
		{
			std::cout << "\t" << i + 1 << ". ";
			accounts[i]->display();
			break;
		}

	}
}

bool AccountsCollection::transfer(const MyString& username, const MyString& toIban, double amount, const MyString& pass)
{
	size_t firstIndex;
	size_t secondIndex;
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (accounts[i]->getUsername() == username)
		{
			firstIndex = i;
		}
		if (accounts[i]->getIban() == toIban)
		{
			secondIndex = i;
		}
	}

	if (accounts[firstIndex]->withdraw(amount) && accounts[firstIndex]->isCorrectPassword(pass))
	{
		accounts[secondIndex]->deposit(amount);
		return true;
	}

	return false;

}

bool AccountsCollection::withdraw(const MyString& username, double sum, const MyString& pass)
{
	if (sum < 0)
		return false;
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (accounts[i]->getUsername() == username)
		{
			if (accounts[i]->getTypeAccount() == 3)
			{
				std::cout << "\tYou cannot withdraw from Savings account!" << std::endl;
				return false;
			}
			if (accounts[i]->withdraw(sum) && accounts[i]->isCorrectPassword(pass))
				return true;

			std::cout << std::endl << "Invalid iban,not enough money or invalid password" << std::endl;
			return false;
		}
	}
	return false;
}

bool AccountsCollection::depozit(const MyString& username, double sum, const MyString& pass)
{
	if (sum < 0)
		return false;
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (accounts[i]->getUsername() == username || accounts[i]->isCorrectPassword(pass))
		{
			accounts[i]->deposit(sum);
			return true;
		}
	}
	return false;
}
