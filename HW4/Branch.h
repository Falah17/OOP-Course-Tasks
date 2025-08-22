//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.
#pragma once


#include "Item.h"


//#define STORE_SIZE 10 


class Branch
{

	vector<Item*> catalog;  //private features
	string location;
	const int catalogCapacity =0;

public:

	// constructor that makes an array(the catalog) and all pointers point to NULL,the other features as defualt
	Branch(string location = "~", int catalogCapacity=0) :location(location),catalogCapacity(catalogCapacity)
	{
	}

	//copy constructor
	Branch(Branch* other):location(other->location),catalogCapacity(other->catalogCapacity)
	{
	}

	// destructor that delete all the cells in the catalog
	~Branch()
	{
		vector<Item*>::iterator p;
		for (p = catalog.begin(); p < catalog.end(); p++)
		{
			delete * p;
		}
	}

	//return the most expensive item from the tybe that takes
	template <typename T = Item*>
	T retrieveFinest(T item)
	{
		vector<Item*>::iterator p;
		vector<Item*>::iterator p1= catalog.end();
		int max;
		for (p = catalog.begin(); p < catalog.end(); p++)
		{
			if (typeid(**p) == typeid(*item) && p1 == catalog.end()) //first time
			{
				p1 = p;
				max = (*p)->getPrice();
			}
			else if (typeid(**p) == typeid(*item) && p1 != catalog.end())
			{
				if ((*p)->getPrice() > max)
				{
					p1 = p;
					max = (*p)->getPrice();
				}
			}
		}
		if (p1 == catalog.end())
		{
			throw NoneExistingItemTypeError();
		}
		T s1 = dynamic_cast<T>(*p1);
		return s1;
	}

	// adding items to the catalog
	void addItem( Item* newItem);

	// deleting items from the catalog
	Item* deleteItem(int id);

	// getters/setters methods for the features
	string getLocation()const;
	void setLocation(const string& newLocation);
	int getCatalogCapacity()const;
	vector<Item*>& getCatalog();

	//auxiliary functions
	int value();
	void print();

	//printing methods
	void print_catalog_by_id();
	void print_catalog_by_price();
};