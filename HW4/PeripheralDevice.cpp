//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#include "PeripheralDevice.h"


//get/set methods for the color 
string PeripheralDevice::getColor() const
{
	return this->color;
}
void PeripheralDevice::setColor(const string& newColor)
{
	this->color = newColor;
}

//get/set for the isWireless
bool PeripheralDevice::getIsWireless() const
{
	return this->isWireless;
}
void PeripheralDevice::setIsWireless(const bool& newIsWireless)
{
	this->isWireless = newIsWireless;
}

//get for if connect
Computer* PeripheralDevice::getIfConnect()
{
	return this->ifConnect;
}

// operator string that take operator string from the Item and adds to it the extra features that belonging to the PeripheralDevice
PeripheralDevice::operator string() const
{
	string s;
	string d = Item::operator string();
	if (this->isWireless == true)
	{
		s = "Wireless";
	}
	else
	{
		s = "Wired";
	}
	string x = d + string(", ") + s + (", ") + this->color;
	return x;
}

//auxiliary function for check if the possible to connect according to the given terms
void PeripheralDevice::if_possible(Computer* computer)
{
	vector<Item*>it = (*computer).getVector();
	vector<Item*>::iterator p;
	int flag = 0;

	for (p = it.begin(); p < it.end(); p++)
	{
		if (typeid(**p) == typeid(*this))
		{
			flag = 1;
			if ((*p) == this)
			{
				flag = 2;
			}
		}
	}
	if (flag == 2)
	{
	}
	else if(it.size() == (*computer).getPorts())
	{
		throw ConnectError();
	}
	else if(flag==1)
	{
		throw ConnectError();
	}
	else
	{
		it.push_back(this);
		this->ifConnect = computer;
		(computer)->setVector(it);
	}
}

/* the connect method that take a computer an connect it to PeripheralDevice and print the feature of both
by using the operator string of the computer and the operator string of the PeripheralDevice*/
void PeripheralDevice::connect( Computer* computer)
{
		string s = PeripheralDevice::operator string();
		cout << s;
		cout << " is Connecting to computer: ";
		cout << computer->operator std::string();
		cout << endl;
}

//disconnect method
void PeripheralDevice::disconnect()
{
	vector<Item*>::iterator p;
	if (this->getIfConnect() != NULL)
	{		
		this->ifConnect->deleteItem(this->getId());
		this->ifConnect = NULL;
	}
}