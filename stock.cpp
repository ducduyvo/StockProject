#ifndef STOCK_H
#define STOCK_H

#include "stock.h"
#endif

#include <iomanip>

#define size 15
#define size1 20

/*
    Constructor for array of item or stock
	The map member fuction includes key word to find the item
*/
Stock::Stock()
{
	revenue = 0;
	list = new map<string, Item>();
}

/*
    Deconstructor
*/
Stock::~Stock()
{
	delete list;
}

// Fuction for adding item to the stock
void Stock::addItem(string name, float price, int amount)
{
	Item i;
	map<string, Item>::iterator find;
	find = list->find(name);
	if (find != list->end())
	{
		cout << "Stock already has this item." << endl;
	}
	else
	{
		i.setName(name);
		i.setPrice(price);
		i.setAmount(amount);
		(*list)[name] = i; // Add each item to an array
	}
}

// Fuction for selling the stock
void Stock::Sell(string name, int n)
{
	map<string, Item>::iterator find;
	find = list->find(name);

	// Sell the item of map member
	if (find != list->end())
	{
		revenue = revenue + find->second.sell(n);
	}
	else
	{
		cout << "Can't find this item!" << endl;
	}
}

// Replensish function for the stock
void Stock::Replenish(string name, int n)
{
	map<string, Item>::iterator find;
	find = list->find(name);
	
	// Add the number of item to map member
	if (find != list->end())
	{
		find->second.add(n);
	}
	else
	{
		cout << "Can't find this item!" << endl;
	}
}

// Clear the stock
void Stock::Clear()
{
	list->clear();
	revenue = 0; // Set revenue to 0 
}

// Find the stock in stock list
void Stock::Find(string seeking)
{
	cout << "Result:" << endl;
	int result = 0;
	cout << left << setw(size1) << "ITEM" << left << setw(size) << "PRICE(euro)" << left << setw(size) << "AMOUNT" << left << setw(size) << "SOLD\n"
		 << endl;
	
	// The integer result is used to check whether this needed stock exists or not
	for (map<string, Item>::iterator i = list->begin(); i != list->end(); i++)
	{
		if (i->second.getName().find(seeking) != string::npos) // Check that the position exists or not
		{
			i->second.printItem();
			++result;
		}
	}
	if (result == 0)
	{
		cout << "Can not found this item!" << endl;
	}
	result = 0;
}

// Print the stock list function
void Stock::printList()
{
	cout << left << setw(size1) << "ITEM" << left << setw(size) << "PRICE(euro)" << left << setw(size) << "AMOUNT" << left << setw(size) << "SOLD\n"
		 << endl;
	for (map<string, Item>::iterator i = list->begin(); i != list->end(); i++)
	{
		i->second.printItem();
	}
	cout << "\nTotal revenue: " << revenue << "e" << endl;
}

/*
    Operator overloading
*/
ostream &operator<<(ostream &out, const Stock &s)
{
	out << s.revenue << endl; // Get output from revenue first, and then all the items later
	for (map<string, Item>::iterator i = s.list->begin(); i != s.list->end(); i++)
	{
		out << i->second;
	}
	return out;
}

istream &operator>>(istream &in, Stock &s)
{
	Item i;
	string revenue;

	delete s.list;
	s.list = new map<string, Item>();

	getline(in, revenue); // Get revenue first
	if (revenue.empty())
	{
		s.revenue = 0;
	}
	else
	{
		s.revenue = stof(revenue); // Convert string to float
	}

	while (in >> i)
	{
		(*s.list)[i.getName()] = i; // Get items from isteam
	}
	return in;
}