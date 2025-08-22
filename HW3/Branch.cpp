//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#include "Branch.h"

static int old = 0;  // an auxiliary variable for adding methods when the catalog is full


// get/set methods for location
string Branch::getLocation() const
{
	return this->location;
}
void Branch::setLocation(const string& newLocation)
{
	this->location = newLocation;
}

// get method for catalog
Item** Branch::getCatalog(int& num)const
{
	num = 0;
	
	for (int i = 0; i < STORE_SIZE; i++)
	{
		if (this->catalog[i] != NULL)
		{
			num++;
		}
	}
	
	return this->catalog;
}


/*add item method, still adding itemsand when the catalog became full put the new item in the place of the oldest item
by using the variable old */
void Branch::addItem( Item* newItem)
{
	
	int flag = 0;
	int i = 0;
	while (i<STORE_SIZE && flag == 0)
	{
		if (catalog[i] == NULL)
		{
			flag = 1;
			catalog[i] = (newItem);
		}
		i++;
	}
	
	if(flag==0)
	{
		delete catalog[old];
		catalog[old] = (newItem);
		old++;
		if (old == STORE_SIZE)   //when our auxiliary variable became equal to the STORE_SIZE return it to 0 
		{
			old =0;
		}
		
	}
}