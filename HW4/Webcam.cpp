//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.
#include "Webcam.h"

// get/set methods 
string Webcam::getResultion() const
{
	return this->resultion;
}
void Webcam::setResultion(const int& newResultion)
{
	this->resultion = newResultion;
}

// operator string that take operator string from the PeripheralDevice and adds to it the extra features that belonging to the Webcam
Webcam::operator string() const
{
	string s = PeripheralDevice::operator string();
	return s + string(", Webcam with " + (this->resultion) + " resolution");
}

/* the connect method that take a computer an connect it to Webcam and print the feature of both
by using the operator string of the computer and the operator string of the Webcam*/
void Webcam::connect(Computer* computer)
{
	cout << "Connecting a webcam" << endl;
	if (this->getIfConnect() == NULL)
	{
		cout << Webcam::operator string();
		cout << " is Connecting to computer: ";
		cout << (computer)->operator std::string();
		cout << endl;
	}
	if_possible(computer);
}
