//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#pragma once
#include "Item.h"

class Computer : public Item
{
	string cpu;     //private features
	bool isLaptop;
	const int usbPortsNumber=0;
	vector<Item*>vector1;

public:

	// the constructor that inheritanced from the Item with adding the private features for the Computer 
	Computer(int price = 0, string manufacturer = "~", string cpu = "~", bool isLaptop = false,int usbPortsNumber=0) :Item(price,manufacturer), cpu(cpu), isLaptop(isLaptop), usbPortsNumber(usbPortsNumber)
	{
	}

	// getters/setters methods for the private features
	string getCpu()const;
	void setCpu(const string& newCpu);
	void setIsLap(const bool& newIsLaptop);
	bool getIsLap()const;
	void setVector(const vector<Item*>& newVector);
	int getPorts()const;
	vector<Item*> getVector();

	//operator string for print the features of the computer
	operator string() const;

	//print method
	void print_connected();

	//delete method
	void deleteItem(int id);
};