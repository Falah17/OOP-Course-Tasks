//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#include "Computer.h"

//get/set methods for the cpu 
string Computer::getCpu() const
{
	return this->cpu;
}
void Computer::setCpu(const string& newCpu)
{
	this->cpu = newCpu;
}

//get/set for the isLaptop
bool Computer::getIsLap() const
{
	return this->isLaptop;
}
void Computer::setIsLap(const bool& newIsLaptop)
{
	this->isLaptop = newIsLaptop;
}

//get for the usbPortsNumber
int Computer::getPorts() const
{
	return this->usbPortsNumber;
}

//get/set for the vector
vector<Item*> Computer::getVector()
{
	return this->vector1;
}
void Computer::setVector(const vector<Item*>& newVector)
{
	this->vector1 = newVector;
}

//auxiliary function for erase a device from the vector of the computer
void Computer::deleteItem(int id)
{
	vector<Item*>::iterator p;
	for (p = this->vector1.begin(); p < this->vector1.end(); p++)
	{
		if ((*p)->getId() == id)
		{
			this->vector1.erase(p);
			break;
		}
	}
}

// operator string that take operator string from the Item and adds to it the extra features that belonging to the Computer
Computer::operator string() const
{
	string s;
	string d = Item::operator string();
	if (this->isLaptop == true)
	{
		s = "Laptop";
	}
	else
	{
		s = "Desktop";
	}
	string x = d + string(", ") + s + (", ") + this->cpu;
	return x;
}

//print the features of the computer and the features of the devices that connected to it
void Computer::print_connected()
{
	cout<<"There are "+std::to_string(this->getVector().size())+" connection to "+this->operator std::string();
	cout << endl;
	vector<Item*> it = this->getVector();
	vector<Item*>::iterator p;

	for (int p = 0; p < it.size(); p++)
	{
		cout << string(*it[p]) << endl;
	}
}