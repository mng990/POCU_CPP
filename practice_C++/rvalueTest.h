#pragma once
#include "Pet.h"
#include "Person.h"

void rvalueTest() {
	Person person1("Me");
	Person person2("Other");
	Pet* petPtr = new Pet("Dog", "Poki");

	person2.SetPet(shared_ptr<Pet>(petPtr));


	// move: lvalue -> rvalue ref
	person1 = move(person2);

	Person copiedPerson(move(person1));

	return;
}

