//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.
#pragma once
#include "PeripheralDevice.h"
class Keyboard :public PeripheralDevice
{
	int numberOfKeys;       //private feature

public:
	// the constructor that inheritanced from the PeripheralDevice with adding the private features for the Keyboard 
	Keyboard(int price = 0, string manufacturer = "~", string color = "~", bool isWireless = false, int numberOfKeys = 0) : PeripheralDevice(price, manufacturer, color, isWireless), numberOfKeys(numberOfKeys)
	{
	}

	//get/set methods for the numberOfKeys
	int getNumOfKeys()const;
	void setNumOfKeys(const int& newNumberOfKeys);

	// connect method that takes a Computer and connect it to Keyboard and print the features of the both 
	void connect(Computer* computer);

	//operator string for print the features of the Keyboard
	operator string() const;
};
