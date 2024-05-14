#pragma once
#include <memory>
#include <string>

using namespace std;

class Person;

class Pet
{
public:
	Pet() = default;
	Pet(const string& type, const string& name);
	~Pet();

	void SetOwner(shared_ptr<Person> owner);
	shared_ptr<Person> GetOwner() { return mOwner.lock(); }

private:
	string mType;
	string mName;
	weak_ptr<Person> mOwner;
};

