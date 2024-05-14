#include "Person.h"
#include <iostream>
#include <string>

Person::Person(const std::string& name) 
	: mName(name), mPet(nullptr)
{
}

Person::Person(Person&& other) noexcept
	:mName(other.mName)
{
	mPet = other.mPet;

	other.mPet.reset();
	other.mName.clear();
}

Person& Person::operator=(Person&& other) noexcept
{
	Person ret(other.mName);

	mPet = other.mPet;

	other.mPet.reset();
	other.mName.clear();

	return ret;
}

void Person::SetPet(shared_ptr<Pet> pet)
{
	mPet = pet;
}

Person::~Person()
{
	cout << mName << " is destroyed.\n";
}