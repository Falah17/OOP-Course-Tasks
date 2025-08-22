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

// operator string that take operator string from the Item and adds to it the extra features that belonging to the PeripheralDevice
PeripheralDevice::operator string() const
{
	string s;
	string d=Item::operator string();
	if (this->isWireless == true)
	{
		s = "Wireless";
	}
	else
	{
		s = "Wired";
	}
	string x =d+ string(", ") + s + (", ") + this->color;
	return x;
}

/* the connect method that take a computer an connect it to PeripheralDevice and print the feature of both
by using the operator string of the computer and the operator string of the PeripheralDevice*/
void PeripheralDevice::connect(const Computer& computer)
{
	cout << PeripheralDevice::operator string();
	cout << " is Connecting to computer :";
	cout << computer.operator std::string();
}