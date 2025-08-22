//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#include "Keyboard.h"

// get/set methods 
int Keyboard::getNumberOfKeys() const
{
	return this->numberOfKeys;
}
void Keyboard::setNumberOfKeys(const int& newNumberOfKeys)
{
	this->numberOfKeys = newNumberOfKeys;
}

// operator string that take operator string from the PeripheralDevice and adds to it the extra features that belonging to the Keyboard
Keyboard::operator string() const
{
	string s= PeripheralDevice::operator string();
	string x =s+ string(", Keyboard with ") + std::to_string(this->numberOfKeys) + (" keys");
	return x;
}


/* the connect method that take a computer an connect it to Keyboard and print the feature of both
by using the operator string of the computer and the operator string of the keyboard*/
void Keyboard::connect(const Computer& computer)
{
	cout << "Connecting a keyboard" << endl;
	cout << Keyboard::operator string();
	cout << " is Connecting to computer: ";
	cout << computer.operator std::string();
	cout << endl;
}