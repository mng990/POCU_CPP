#include "Inventory.h"
#include "Exception.h"

Inventory::Inventory(int count) 
	: mSlots(new int[count])
{
	if (mSlots == NULL)
	{
		throw SlotNullException();
	}
}