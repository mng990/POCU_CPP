#pragma once
#include "Person.h"


void refCount() 
{
	Person* person = new Person("Coco");
	Person* copiedPerson = person;

	// copiedPerson�� �߰��Ǿ��⿡
	// �������� refCount++
	copiedPerson->AddRef();


	// ���� �����Ͱ� nullptr�� �Ǹ鼭
	// ������ �Ҹ�(refCount--)
	person->Release();
	person = nullptr;

	copiedPerson->Release();
	copiedPerson = nullptr;

	return ;
}