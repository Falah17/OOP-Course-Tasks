//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#pragma once

#include "Cpu.h"

class Computer
{
	Cpu cpu;                 //private features
	string manufacturerName;
	int yearOfManufacture;
	string color;
	bool isItLaptop;

public:
	 

	//build default constructor initializes everything
	Computer(Cpu cpu = (0, "~", 0), string manufacturerName = "~", int yearOfManufacture = 0, string color = "~", bool isItLaptop = false)
	{
		this->cpu = cpu;
		this->yearOfManufacture = yearOfManufacture;
		this->isItLaptop = isItLaptop;

		// checking if the name from the user is more than 10 chars ,if yes we swap the name to default value
		if (manufacturerName.length() > 10)
		{
			cout << "Manufacturer's name length is too long" << endl;
			this->manufacturerName = "~";
		}
		else
		{
			this->manufacturerName = manufacturerName;
		}

		// checking if the color from the user is more than 10 chars ,if yes we swap the color to default value
		if (color.length() > 10)
		{
			cout << "Color string length is too long" << endl;
			this->color = "~";
		}
		else
		{
			this->color = color;
		}
	}

	// class get/set methods

	Cpu getCpu()const;
	void setCpu(const Cpu& newCpu);

	string getManufacturer()const;
	void setManufacturer(const string& newManufacturerName);

	int getYear()const;
	void setYear(const int& newYearOfManufacture);

	string getColor()const;
	void setColor(const string& newColor);

	bool getIsLaptop()const;
	void setIsLaptop(const bool& newIsItLaptop);

	//class print method
	void print()const;
};