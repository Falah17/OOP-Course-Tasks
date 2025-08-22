//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#include "Item.h"

// Class get methods
int Item::getPrice() const
{
	return this->price;
}
int Item::getId() const
{
	return this->id;
}
string Item::getManufacturer() const
{
	return this->manufacturer;
}

// Class set methods
void Item::setPrice(const int& newPrice)
{
	this->price = newPrice;
}
void Item::setManufacturer(const string& newManufacturer)
{
	this->manufacturer = newManufacturer;
}


//operator string that print the features of the item
Item::operator string() const
{
	string x = string("id ") + std::to_string(this->id) + (": ") + this->manufacturer + (" ") + std::to_string(this->price) + "$";
	return x;
}

