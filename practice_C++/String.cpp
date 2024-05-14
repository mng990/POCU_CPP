#include "String.h"
#include <iostream>


String::String(): 
	mLength(0), mCapacity(15) 
{
	mChars = new char[mCapacity + 1];
}

String::String(const String& str)
	:mLength(str.mLength), mCapacity(str.mCapacity)
{
	mChars = new char[mLength+1];
}

String::~String()
{
	delete[] mChars;
}
