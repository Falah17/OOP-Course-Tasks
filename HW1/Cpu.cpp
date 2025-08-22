//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#include "Cpu.h"


//clockRate get/set methods
double Cpu::getClockRate() const
{
	return this->clockRate;
}
void Cpu::setClockRate(const double& newClockRate)
{
	this->clockRate = newClockRate;
}


//manufacturerName get/set methods
string Cpu::getManufacturer()const
{
	return this->manufacturerName;
}
void Cpu::setManufacturer(const string& newManufacturerName)
{
	if (newManufacturerName.length() > 10)
	{
		cout << "Manufacturer's name length is too long" << endl;
	}
	else
	{
		this->manufacturerName = newManufacturerName;
	}
}


//yearOfManufacturing get/set methods
int Cpu::getYear()const
{
	return this->yearOfManufacturing;
}
void Cpu::setYear(const int& newYearOfManufacturing)
{
	this->yearOfManufacturing = newYearOfManufacturing;
}


// print method
void Cpu::print()const
{
	cout << "Cpu clockRate: " << this->clockRate << endl;
	cout << "Cpu manufacturer: " << this->manufacturerName << endl;
	cout << "Cpu year: " << this->yearOfManufacturing << endl;
}