//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.
#pragma once
#include "PeripheralDevice.h"
class Mouse :public PeripheralDevice
{
	int dpi;                  //private feature

public:
	// the constructor that inheritanced from the PeripheralDevice with adding the private features for the Mouse 
	Mouse(int price = 0, string manufacturer = "~", string color = "~", bool isWireless = false, int dpi = 0) : PeripheralDevice(price, manufacturer, color, isWireless), dpi(dpi)
	{
	}

	//get/set methods for the dpi
	int getDpi()const;
	void setDpi(const int& newDpi);

	// connect method that takes a Computer and connect it to Mouse and print the features of the both 
	void connect(Computer* computer);

	//operator string for print the features of the Mouse
	operator string() const;
};
