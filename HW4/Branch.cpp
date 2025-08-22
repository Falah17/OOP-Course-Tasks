//Student1 Falah Abu-Raya, falah.aburaya.17@gmail.com, 212530034.
//Student2 Veronica sliman, veronicasliman5@gmail.com, 322782244.

#include "Branch.h"
#include "HWExceptions.h"


static int old = 0;  // an auxiliary variable for adding methods when the catalog is full


// get/set methods for location
string Branch::getLocation() const
{
	return this->location;
}
void Branch::setLocation(const string& newLocation)
{
	this->location = newLocation;
}

//get the capacity
int Branch::getCatalogCapacity() const
{
	return this->catalogCapacity;
}

//return the catalog
vector<Item*>& Branch::getCatalog()
{
	return catalog;
}

//adding an item to the branch after checking if we can add it according to the givem terms
void Branch::addItem(Item* newItem)
{
	vector<Item*>::iterator p;
		p = std::find(catalog.begin(), catalog.end(), newItem);
		if (p != catalog.end())
		{
			throw ExistingItemError();
		}
		if (catalog.size() == this->catalogCapacity)
		{
			throw FullCatalogError();
		}
		catalog.push_back(newItem);		
}

//deleting an item to the branch after checking if we can add it according to the givem terms
Item* Branch::deleteItem(int id)
{
	vector<Item*>::iterator p;
	Item* p1=NULL;
	for (p = catalog.begin(); p < catalog.end(); p++)
	{
		if ((*p)->getId() == id)
		{
			p1 = *p;
			catalog.erase(p);
			return p1;
		}
	}
		throw NonExistingItemError();
}

//the value of the branch
int Branch::value()
{
	int sum=0;
	vector<Item*>::iterator p;
	for (p=catalog.begin(); p < catalog.end(); p++)
	{
		sum += (*p)->getPrice();
	}
	return sum;
}

//auxiliary function for printing
void Branch::print()
{
	cout << "Printing KSF branch in " + this->location << endl;
	cout << "There are " + std::to_string(catalog.size()) + " item in the catalog" << endl;
	cout << "Catalog value is: " + std::to_string(value()) << endl;
}

//auxiliary functions to compare
bool compare_id(Item* a1, Item* a2)
{
	return(a1->getId() < a2->getId());
}
bool compare_price(Item* a1, Item* a2)
{
	return(a1->getPrice() < a2->getPrice());
}

//printing by order the id
void Branch::print_catalog_by_id()
{
	 print();
	stable_sort(catalog.begin(), catalog.end(), compare_id);
	for (int p=0; p <catalog.size(); p++)
	{
		cout << string(*catalog[p]) << endl;
	}
}

// printing according to the price
void Branch::print_catalog_by_price()
{
	 print();
	stable_sort(catalog.begin(), catalog.end(), compare_price);
	for (int p = 0; p < catalog.size(); p++)
	{
		cout << string(*catalog[p]) << endl;
	}
}