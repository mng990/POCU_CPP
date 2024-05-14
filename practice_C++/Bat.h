#pragma once
#include "IWalkable.h"
#include "IFlyable.h"
#include <iostream>

using namespace std;

class Bat:public IWalkable, public IFlyable
{
public:
	void Walk() const {
		cout << "Bat is walking.." << endl;
	}

	void Fly() const {
		cout << "Bat is flying!!" << endl;
	}
};

