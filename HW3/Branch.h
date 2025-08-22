//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#pragma once
#include "Item.h"

#define STORE_SIZE 10 


class Branch
{

	Item** catalog;  //private features
	string location;

public:

	// constructor that makes an array(the catalog) and all pointers point to NULL,the other features as defualt
	Branch(string location = "~") : catalog(new Item* [STORE_SIZE]), location(location)
	{
		for (int i = 0; i < STORE_SIZE; i++)
		{
			catalog[i] = NULL;
		}
	}

	// destructor that delete all the cells in the catalog
	~Branch()
	{
		for (int i = 0; i < STORE_SIZE; i++)
		{
			delete[]catalog[i];
		}
	}


	// adding items to catalog
	void addItem( Item* newItem);  

	// getters/setters methods for the features
	Item** getCatalog(int& num) const;
	string getLocation()const;
	void setLocation(const string& newLocation);



};