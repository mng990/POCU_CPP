#include "Pet.h"
#include <iostream>

using namespace std;

Pet::Pet(const string& type, const string& name)
	: mType(type), mName(name)
{
}

Pet::~Pet()
{
	cout << mName << " is deleted.\n";
}

void Pet::SetOwner(shared_ptr<Person> owner)
{
	mOwner = owner;
}
