//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#pragma once
#include "Item.h"
#include "Computer.h"

class PeripheralDevice : public Item
{
	string color;            //private features
	bool isWireless;


public:

	// the constructor that inheritanced from the Item with adding the private features for the PeripheralDevice 
	PeripheralDevice(int price = 0, string manufacturer = "~", string color = "~", bool isWireless = false): Item(manufacturer, price),color(color), isWireless(isWireless)
	{
	}


	// getters/setters methods for the private features
	string getColor()const;
	bool getIsWireless()const;
	void setColor(const string& newColor);
	void setIsWireless(const bool& newIsWireless);
	
	//operator string for print the features of the PeripheralDevice
	virtual operator string() const=0;

	// connect method that takes computer and connect it to PeripheralDevice and print the features of the both
	virtual void connect(const Computer& computer);

};
