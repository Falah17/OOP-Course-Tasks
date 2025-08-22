#pragma once
#include <stdio.h>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Cpu
{
	double clockRate;    //private features
	string manufacturerName;
	int yearOfManufacturing;

public:

	//build default constructor initializes everything
	Cpu(double clockRate = 0, string manufacturerName = "~", int yearOfManufacturing = 0)
	{
		this->clockRate = clockRate;
		this->yearOfManufacturing = yearOfManufacturing;

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
	}

	// class get/set methods

	double getClockRate() const;
	void setClockRate(const double& newClockRate);

	string getManufacturer()const;
	void setManufacturer(const string& newManufacturerName);

	int getYear()const;
	void setYear(const int& newYearOfManufacturing);

	//class print method
	void print()const;
};
