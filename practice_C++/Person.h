#pragma once
#include <memory>
#include <string>
#include "Pet.h"

using namespace std;

class Pet;

class Person
{
public:
	Person(const string& name);
	Person(Person&& other) noexcept;
	Person& operator=(Person&& other) noexcept;
	Person() = default;
	~Person();

	void SetPet(shared_ptr<Pet> pet);
	shared_ptr<Pet> GetPet() { return mPet; }

private:
	string mName;
	shared_ptr<Pet> mPet;
};

