//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#include "Computer.h"

//cpu get/set methods
Cpu Computer::getCpu()const
{
	return this->cpu;
}
void Computer::setCpu(const Cpu& newCpu)
{
	this->cpu = newCpu;
}

//manufacturerName get/set methods
string Computer::getManufacturer()const
{
	return this->manufacturerName;
}
void Computer::setManufacturer(const string& newManufacturerName)
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

//yearOfManufacture get/set methods
int Computer::getYear()const
{
	return this->yearOfManufacture;
}
void Computer::setYear(const int& newYearOfManufacture)
{
	this->yearOfManufacture = newYearOfManufacture;
}

//color get/set methods
string Computer::getColor()const
{
	return this->color;
}
void Computer::setColor(const string& newColor)
{
	if (newColor.length() > 10)
	{
		cout << "Color string length is too long" << endl;
	}
	else
	{
		this->color = newColor;
	}
}

//isItLaptop get/set methods
bool Computer::getIsLaptop()const
{
	return this->isItLaptop;
}
void Computer::setIsLaptop(const bool& newIsItLaptop)
{
	this->isItLaptop = newIsItLaptop;
}

//print method
void Computer::print()const
{
	cout << "Cpu clockRate: " << this->cpu.getClockRate() << endl;
	cout << "Cpu manufacturer: " << this->cpu.getManufacturer() << endl;
	cout << "Cpu year: " << this->cpu.getYear() << endl;
	cout << "Computer manufacturer: " << this->manufacturerName << endl;
	cout << "Computer year: " << this->yearOfManufacture << endl;
	cout << "Computer color: " << this->color << endl;
	if (this->isItLaptop == 1)
	{
		cout << "Computer is laptop: True" << endl;
	}
	else
	{
		cout << "Computer is laptop: False" << endl;
	}

}
