//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#include"Store.h"

//name get/set methods
string Store::getName() const
{
	return this->name;
}

void Store::setName(const string& newName)
{
	if (newName.length() > 10)
	{
		cout << "store's name length is too long" << endl;
	}
	else
	{
		this->name = newName;
	}
}

//computer get method
const Computer* Store ::getComputer() const
{
	return this->computers;
}

//computersNumber get method
int Store::getComputersNumber()const
{
	return this->computersNumber;
}


// adding computer method 
void Store::addComputer(const Computer& newComputer)
{
	if (MAX_COMPUTERS_NUMBER <= this->computersNumber)
	{
		cout << "The store is full!" << endl;
	}
	else
	{
		this->computers[this->computersNumber] = newComputer;
		this->computersNumber++;
	}
}

//print by name/year methods
void Store::printComputersByName()
{
	cout << "There are " << this->computersNumber << " computers in the store. The computers:" << endl;
	Computer tempStore[MAX_COMPUTERS_NUMBER];

	for (int i = 0; i < this->computersNumber; i++)
	{
		tempStore[i] = this->computers[i];
	}

	Computer t1, t2;
	string s1, s2;
	for (int i = 0; i < this->computersNumber; i++)
	{
		
		for (int j = 0; j < this->computersNumber; j++)
		{
			if (i > j)
			{
				t1 = tempStore[i];
				s1 = t1.getManufacturer();
				t2 = tempStore[j];
				s2 = t2.getManufacturer();
				if ((s1.compare(s2))>0)
				{
					tempStore[j] = t1;
					tempStore[i] = t2;
					
				}
			}
		}

	}
	for (int i = this->computersNumber - 1; i >= 0; i--)
	{
		cout << "Computer " << (this->computersNumber - i) << endl;
		tempStore[i].print();
		cout << endl;
	}
}


void Store::printComputersByYear()
{
	
	cout << "There are " << this->computersNumber << " computers in the store. The computers:" << endl;

	Computer tempStore[MAX_COMPUTERS_NUMBER];

	for (int i = 0; i < this->computersNumber; i++)
	{
		tempStore[i] = this->computers[i];
	}

	Computer t1, t2;

	for (int i = 0; i < this->computersNumber ; i++)
	{
		
		for (int j = 0; j < this->computersNumber; j++)
		{
			if (i > j)
			{
				t1 = tempStore[i];
				t2 = tempStore[j];
				if (t1.getYear() > t2.getYear())
				{
					tempStore[j] = t1;
					tempStore[i] = t2;
				}
			}
		}

	}
	for (int i = this->computersNumber-1; i >= 0; i--)
	{
		cout << "Computer " << (this->computersNumber-i) << endl;
		tempStore[i].print();
		cout << endl;
	}
}