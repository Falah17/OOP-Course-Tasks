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


// operator string that take operator string from the Item and adds to it the extra features that belonging to the Computer
Computer::operator string() const
{
	string s;
	string d=Item::operator string();
	if (this->isLaptop == true)
	{
		s = "Laptop";
	}
	else
	{
		s = "Desktop";
	}

	string x =d+ string(", ") + s + (", ") + this->cpu;
	return x;
}