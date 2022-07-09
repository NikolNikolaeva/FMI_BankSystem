#pragma once
#include "MyString.h"

class Customer
{
private:

	size_t id;
	MyString name;
	MyString address;

	void setId(size_t id);

protected:

	void setName(const MyString& name);
	void setAddress(const MyString& address);

public:

	Customer() = default;
	Customer(size_t id, const MyString& name, const MyString& address);

	const MyString& getName() const;
	const MyString& getAddress() const;
	size_t getId() const;

	bool operator==(const Customer& other);

	void printCustomer() const;
};