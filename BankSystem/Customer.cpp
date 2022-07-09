#include "Customer.h"
#include <iostream>

void Customer::setName(const MyString& name)
{
	this->name=name;
}
void Customer::setId(size_t id)
{
	this->id = id;
}
void Customer::setAddress(const MyString& address)
{
	this->address = address;
}

Customer::Customer(size_t id,const MyString& name,const MyString& address)
{
	setId(id);
	setName(name);
	setAddress(address);
}

const MyString& Customer::getName() const
{
	return name;
}
const MyString& Customer::getAddress() const
{
	return address;
}
size_t Customer::getId() const
{
	return id;
}

void Customer::printCustomer() const
{
	std::cout <<"ID: "<< id << ", name: " << name << ", address: " << address << std::endl;
}

bool Customer::operator==(const Customer& other)
{
	return (name == other.name && address == other.address && id == other.id);
}