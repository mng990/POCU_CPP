#pragma once
class String
{
public:
	String();
	String(const String& str);
	~String();

	int getLength()	{ return mLength;	}
	int getCapacity()	{ return mCapacity; }

private:
	int mLength;
	int mCapacity;
	char* mChars;
};

