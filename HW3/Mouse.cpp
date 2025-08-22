//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#include "Mouse.h"

// get/set methods 
int Mouse::getDpi() const
{
	return this->dpi;
}
void Mouse::setDpi(const int& newDpi)
{
	this->dpi = newDpi;
}

// operator string that take operator string from the PeripheralDevice and adds to it the extra features that belonging to the Mouse
Mouse::operator string() const
{
	string s = PeripheralDevice::operator string();
	
	//string x = string(", Mouse with dpi : ") + std::to_string(this->dpi) ;
	return s+string(", Mouse with dpi : ") + std::to_string(this->dpi);
}

/* the connect method that take a computer an connect it to Mouse and print the feature of both
by using the operator string of the computer and the operator string of the Mouse*/
void Mouse::connect(const Computer& computer)
{
	cout << "Connecting a mouse" << endl;
	cout << Mouse::operator string();
	cout << " is Connecting to computer: ";
	cout << computer.operator std::string();
	cout << endl;
}
