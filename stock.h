#ifndef ITEM_H
#define ITEM_H

#include "Item.h"
#endif

#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

class Stock
{
public:
	Stock();
	~Stock();
	void addItem(string name, float price, int amount);
	void Replenish(string i, int n);
	void Sell(string i, int n);
	void Find(string i);
	void printList();
	void Clear();
	friend ostream &operator<<(ostream &out, const Stock &s);
	friend istream &operator>>(istream &in, Stock &i);

private:
	float revenue;
	map<string, Item> *list; // an array of item based on their name
};