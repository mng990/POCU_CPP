#pragma once
#include "Person.h"


void refCount() 
{
	Person* person = new Person("Coco");
	Person* copiedPerson = person;

	// copiedPerson이 추가되었기에
	// 수동으로 refCount++
	copiedPerson->AddRef();


	// 원시 포인터가 nullptr이 되면서
	// 소유권 소멸(refCount--)
	person->Release();
	person = nullptr;

	copiedPerson->Release();
	copiedPerson = nullptr;

	return ;
}