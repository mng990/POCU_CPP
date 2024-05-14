#pragma once
#include <iostream>
#include "Person.h"
#include "Pet.h"

using namespace std;

void circulationTest() {
	shared_ptr<Person> person = make_shared<Person>("RJH");
	shared_ptr<Pet> pet = make_shared<Pet>("Cat", "Mew");


	cout << "Owner: " << person.use_count() << " Pet: " << pet.use_count() << "\n";
	
	person->SetPet(pet);
	pet->SetOwner(person);

	cout << "Owner: " << person.use_count() << " Pet: " << pet.use_count() << "\n";
		
	cout << "Owner: " << person->GetPet().use_count() << "\n";

	return;
}