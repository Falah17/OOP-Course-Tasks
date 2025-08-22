#pragma once
//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#include <stdio.h>
#include <iostream>
#include <string>
#include"HWExceptions.h"
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ostream;

static int staticId = 1; //an auxiliary variable for increase the id when we build an item 

class Item
{
	const int id = staticId++;     //private features
	string manufacturer;
	int price;
	int connect;


public:

	//the constructor
	Item(int price = 0,string manufacturer = "~")
	{
		this->price = price;
		this->manufacturer = manufacturer;
	}

	//the destrucrtor , put it virtual because we want to inherit this class to other classes
	virtual ~Item()
	{
		cout << "Throwing away an item" << endl;
	}

	//operator == , for comparison between two Items
	bool operator==(const Item& i1)
	{
		if ((this->manufacturer == i1.manufacturer) && (this->price == i1.price))
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	//operator == , for comparison between two Items
	bool operator!=(const Item& i1)
	{
		if (*this == i1)
		{
			return false;
		}
		else
		{
			return true;
		}

	}


	//operator string for print the features of the Item , put it virtual because we want to inherit this class to other classes
	virtual operator string() const ;

	// Class get methods
	int getPrice() const;
	int getId() const;
	string getManufacturer() const;

	// Class set methods
	void setPrice(const int& newPrice);
	void setManufacturer(const string& newManufacture);



};
