//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.
#pragma once
#include "PeripheralDevice.h"
class Webcam :public PeripheralDevice
{
	string resultion;                  //private feature

public:
	// the constructor that inheritanced from the PeripheralDevice with adding the private features for the Webcam 
	Webcam(int price = 0, string manufacturer = "~", string color = "~", bool isWireless = false, string resultion = "~") : PeripheralDevice(price, manufacturer, color, isWireless), resultion(resultion)
	{
	}

	//get/set methods for the dpi
	string getResultion()const;
	void setResultion(const int& newResultion);

	// connect method that takes a Computer and connect it to Webcam and print the features of the both 
	void connect(Computer* computer);

	//operator string for print the features of the Webcam
	operator string() const;
};
