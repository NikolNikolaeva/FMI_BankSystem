#include "Bank.h"
#include <iostream>

void Bank::setName(const MyString& name)
{
	this->name = name;
}
void Bank::setAddress(const MyString& address)
{
	this->address = address;
}
const MyString& Bank::getName() const
{
	return name;
}
const MyString& Bank::getAddress() const
{
	return address;
}
const Vector<Customer>& Bank::getCustomersList() const
{
	return customerList;
}

void Bank::addCustomer(const Customer& customer)
{
	for (size_t i = 0; i < customerList.getSize(); i++)
	{
		if (customerList[i] == customer)
		{
			throw std::logic_error("Already added");
		}
	}
	customerList.pushBack(customer);
	log.pushBack("Add customer");
}
void Bank::deleteCustomer(size_t id)
{
	bool validId = false;
	for (size_t i = 0; i < customerList.getSize(); i++)
	{
		if (customerList[i].getId() == id)
		{
			customerList.popAt(i);
			log.pushBack("Delete customer");
			validId = true;
			break;
		}

	}

	if (!validId)
		std::cout << "No customer with this id" << std::endl;

}
void Bank::addAccount(size_t id, double& overdtaft, double& interestRate)
{
	bool validId = false;

	if (customerList.getSize() == 0)
	{
		std::cout << "\tNo customers yet!" << std::endl;
	}

	for (size_t i = 0; i < customerList.getSize(); i++)
	{
		if (customerList[i].getId() == id)
		{

			validId = true;
			bool valicAccount = false;
			MyString typeAcc;
			std::cout << "\tType account (Normal, Privilege, Savings) : ";
			std::cin >> typeAcc;
			if (typeAcc == "Normal")
			{
				valicAccount = true;
			}
			else if (typeAcc == "Privilege")
			{
				valicAccount = true;
			}
			else if (typeAcc == "Savings")
			{
				valicAccount = true;
			}
			else
			{
				std::cout << "	Invalid type of account" << std::endl;
			}

			if (valicAccount == true)
			{
				MyString username;
				std::cout << "	Enter username for your account: ";
				std::cin >> username;
				MyString pass;
				std::cout << "	Enter password for your account: ";
				std::cin >> pass;
				double money;
				std::cout << "	How much money do you want to add: ";
				std::cin >> money;
				MyString newIban;
				std::cout << "	Enter your Iban: ";
				std::cin >> newIban;

				if (typeAcc == "Normal")
				{
					if (!(accounts.addNormalAccount(customerList[i], username, pass, newIban, money)))
						std::cout << "\tAlready exist account with same IBAN!" << std::endl;
					else
					{
						std::cout << "\tAccount added succsessfully!" << std::endl;
						log.pushBack("Add Normal account");
					}
				}
				if (typeAcc == "Privilege")
				{
					if (!(accounts.addPrivilegeAccount(customerList[i], username, pass, newIban, money, overdraft)))
						std::cout << "\tAlready exist account with same IBAN!" << std::endl;
					else
					{
						std::cout << "\tAccount added succsessfully!" << std::endl;
						log.pushBack("Add Privilege account");
					}
				}
				if (typeAcc == "Savings")
				{

					if (!(accounts.addSavingsAccount(customerList[i], pass, username, newIban, money, interestRate)))
						std::cout << "\tAlready exist account with same IBAN!" << std::endl;
					else
					{
						std::cout << "\tAccount added succsessfully!" << std::endl;
						log.pushBack("Add Savings account");
					}

				}
			}
		}
	}

	if (validId == false)
		std::cout << "	No customer with this id" << std::endl;
}
void Bank::deleteAccount(MyString& username, MyString pass)
{
	if (accounts.deleteAccount(username, pass))
		log.pushBack("Delete account");
}
void Bank::listCustomers() const
{
	for (size_t i = 0; i < customerList.getSize(); i++)
	{
		std::cout << "\t" << i + 1 << ". ";
		customerList[i].printCustomer();
	}
}
void Bank::listAccounts() const
{
	accounts.printInfoAccounts();
}
void Bank::listCustomerAccount(size_t id) const
{
	accounts.printAccountsForOneCustomer(id);
}
void Bank::exportLog()
{
	std::ofstream file("BankTransactions.txt");

	if (!file.is_open())
	{
		throw std::logic_error("File cannot be open!");
	}

	for (size_t i = 0; i < log.getSize(); i++)
	{
		std::cout << "\t" << i + 1 << ". ";
		file << log[i].c_str() << '\n';
	}

}
void Bank::transfer(const MyString& fromIban, const MyString& toIban, double amount, const MyString& pass)
{
	if (accounts.transfer(fromIban, toIban, amount, pass))
		log.pushBack("Transfer money between two accounts");
	else
	{
		std::cout << "Not enough money or unvalid account" << std::endl;
	}
}
void Bank::display() const
{
	std::cout << "\tBank name: " << name << ", adress: " << address << ", customers: " << customerList.getSize() << ", accounts: " << accounts.getAccountaCount() << std::endl;
}


void Bank::setOverdraft(double overdraft)
{
	this->overdraft = overdraft;
}
void Bank::setInterestRate(double interestRate)
{
	this->interestRate = interestRate;
}

void Bank::interface()
{
	std::cout << "	Hello! Create a bank" << std::endl;
	MyString bankName, bankAdddress;
	double currOverdraft, currInterestRate;

	std::cout << "	Enter name: ";
	std::cin >> bankName;
	setName(bankName);
	std::cout << "	Enter address : ";
	std::cin >> bankAdddress;
	setAddress(bankAdddress);
	std::cout << "	Enter overdraft: ";
	std::cin >> currOverdraft;
	setOverdraft(currOverdraft);
	std::cout << "	Enter interestRate: ";
	std::cin >> currInterestRate;
	setInterestRate(currInterestRate);


	int num;

	while (true)
	{
		std::cout << std::endl;
		std::cout << "\tChoose the number from the list" << std::endl;
		std::cout << "	1. Edit " << std::endl;
		std::cout << "	2. List" << std::endl;
		std::cout << "	3. Action" << std::endl;
		std::cout << "	4. Display info for the bank" << std::endl;
		std::cout << "	5. Quit (saves the logs in file)" << std::endl;
		std::cout << "	-> ";
		std::cin >> num;

		if (num == 1)
		{
			int edditCommand;
			std::cout << "	1. Customer " << std::endl;
			std::cout << "	2. Account" << std::endl;
			std::cout << "	->";
			std::cin >> edditCommand;

			if (edditCommand == 1)
			{
				int custCommand;
				std::cout << "	1. Add new customer " << std::endl;
				std::cout << "	2. Delete customer" << std::endl;
				std::cout << "	->";
				std::cin >> custCommand;

				if (custCommand == 1)
				{
					MyString name;
					std::cout << "	Enter name: ";
					std::cin >> name;
					MyString address;
					std::cout << "	Enter adress: ";
					std::cin >> address;
					size_t id;
					std::cout << "	Enter id: ";
					std::cin >> id;

					Customer newCust(id, name, address);
					addCustomer(newCust);
					std::cout << std::endl << "	Successfully added!" << std::endl;
				}
				else if (custCommand == 2)
				{
					std::cout << "\tEnter id of custumer: ";
					size_t id;
					std::cin >> id;
					deleteCustomer(id);
					std::cout << "	Successfully deleted!" << std::endl;
				}
				else
				{
					std::cout << "\tInvalid commnad" << std::endl;
					continue;
				}
			}
			else if (edditCommand == 2)
			{
				int accCommand;
				std::cout << "	1. Add new account " << std::endl;
				std::cout << "	2. Delete account" << std::endl;
				std::cout << "	->";
				std::cin >> accCommand;

				if (accCommand == 1)
				{
					std::cout << "	Enter id of the customer: ";
					size_t id;
					std::cin >> id;
					addAccount(id,overdraft,interestRate);
				}
				else if (accCommand == 2)
				{
					std::cout << "\tEnter username of custumer: ";
					MyString username;
					std::cin >> username;
					std::cout << "\tEntrer password of account: ";
					MyString pass;
					std::cin >> pass;
					deleteAccount(username, pass);
					std::cout << "	Successfully deleted!" << std::endl;
				}
				else
				{
					std::cout << "	Invalid commnad" << std::endl;
					continue;
				}
			}
			else
			{
				std::cout << "	Invalid commnad" << std::endl;
				continue;
			}
		}
		else if (num == 2)
		{
			int listComm;
			std::cout << "	1. List all customers" << std::endl;
			std::cout << "	2. List all accounts" << std::endl;
			std::cout << "	3. List customer account" << std::endl;
			std::cout << "	4. List log" << std::endl;
			std::cout << "	->";
			std::cin >> listComm;

			if (listComm == 1)
			{
				listCustomers();
			}
			else if (listComm == 2)
			{
				listAccounts();
			}
			else if (listComm == 3)
			{
				std::cout << "\tEnter id ot ther customer: ";
				size_t id;
				std::cin >> id;
				listCustomerAccount(id);
			}
			else if (listComm == 4)
			{
				for (size_t i = 0; i < log.getSize(); i++)
				{
					std::cout << log[i].c_str() << std::endl;
				}
			}
			else
			{
				std::cout << "\tNot from the options" << std::endl;
			}

		}
		else if (num == 3)
		{
			int acctComm;
			std::cout << "	1. Withdraw from account" << std::endl;
			std::cout << "	2. Deposit to account" << std::endl;
			std::cout << "	3. Transfer" << std::endl;
			std::cout << "	->";
			std::cin >> acctComm;

			if (acctComm == 1)
			{
				MyString username;
				std::cout << "\tEnter username: ";
				std::cin >> username;
				double amount;
				std::cout << "\tEnter amount: ";
				std::cin >> amount;
				MyString pass;
				std::cout << "\tEnter password: ";
				std::cin >> pass;


				if (accounts.withdraw(username, amount, pass))
					log.pushBack("Withdraw from account");
			}
			else if (acctComm == 2)
			{
				MyString username;
				std::cout << "\tEnter username: ";
				std::cin >> username;
				double amount;
				std::cout << "\tEnter amount: ";
				std::cin >> amount;
				MyString pass;
				std::cout << "\tEnter password: ";
				std::cin >> pass;

				if (accounts.depozit(username, amount, pass))
					log.pushBack("Deposit to account");
				else
					std::cout << std::endl << "Invalid iban or password" << std::endl;
			}
			else if (acctComm == 3)
			{
				MyString username;
				std::cout << "\tEnter username of your account: ";
				std::cin >> username;
				MyString iban2;
				std::cout << "\tEnter iban for account to transfer: ";
				std::cin >> iban2;
				double amount;
				std::cout << "\tEnter amount: ";
				std::cin >> amount;
				MyString pass;
				std::cout << "\tEnter password: ";
				std::cin >> pass;

				transfer(username, iban2, amount, pass);
			}
		}
		else if (num == 4)
		{
			display();
		}
		else if (num == 5)
		{
			exportLog();
			break;
		}
		else
		{
			std::cout << "Invalid command" << std::endl;
			continue;
		}
	}
}