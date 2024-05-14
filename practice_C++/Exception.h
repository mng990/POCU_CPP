#pragma once
#include <exception>

using namespace std;

struct SlotNullException : public exception
{
	const char* what() const throw()
	{
		return "Slot is NULL";
	
	}
};