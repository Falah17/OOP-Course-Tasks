#pragma once
#include <iostream>
#include<exception>
using std::exception;

class FullCatalogError :public exception
{
		const char* what() const throw()
	{
		return "Trying to add an item to a full catalog";
	}
};

class NonExistingItemError :public exception
{
	const char* what() const throw()
	{
		return "Trying to delete an item with a non existing id";
	}
};

class ConnectError :public exception
{
	const char* what() const throw()
	{
		return "Failed connection attempt";
	}
};

class ExistingItemError :public exception
{
	const char* what() const throw()
	{
		return "Trying to add an item with an id already in the catalog";
	}
};

class NoneExistingItemTypeError :public exception 
{
	const char* what() const throw()
	{
		return "Trying to get an item with a non existing type";
	}
};

