#pragma once
#include "IWalkable.h"
#include "IFlyable.h"
#include <iostream>

using namespace std;

class Cat : public IWalkable
{
public:
	void Walk() const {
		cout << "Walk Walk" << endl;
	}
};

