//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#pragma once
#include "Computer.h"
#define MAX_COMPUTERS_NUMBER 10

class Store
{
	string name;      //private features
	Computer computers[MAX_COMPUTERS_NUMBER];
	int computersNumber;

public:

	//build default constructor initializes everything
	Store(string name = "~", int computersNumber = 0)
	{
		this->computersNumber = computersNumber;

		// checking if the name from the user is more than 10 chars ,if yes we swap the name to default value
		if (name.length() > 10)
		{
			cout << "Store's name length is too long" << endl;
			this->name = "~";
		}
		else
		{
			this->name = name;
		}
	}

	// class get/set methods

	string getName()const;
	void setName(const string& newName);

	int getComputersNumber()const;

	const Computer* getComputer() const;

	//class add method
	void addComputer(const Computer& computer);

	//class print methods
	void printComputersByName();
	void printComputersByYear();
};
