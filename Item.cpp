#ifndef ITEM_H
#define ITEM_H

#include "Item.h"
#endif

#include <iomanip>
#define size 15
#define size1 20

/*
    Constructor
*/

Item::Item(string name, float price, int amount, int sold)
{
	m_name = name;
	m_price = price;
	m_amount = amount;
	m_sold = sold;
}
/*
    Copy constructor 
*/

Item::Item(const Item &i)
{
	m_name = i.m_name;
	m_price = i.m_price;
	m_amount = i.m_amount;
	m_sold = i.m_sold;
}

string Item::getName() const { return m_name; }

float Item::getPrice() const { return m_price; }

int Item::getAmount() const { return m_amount; }

int Item::getSold() const { return m_sold; }

// Sell item function
float Item::sell(int n)
{
	if (n > m_amount)
	{
		cout << "Not enough amount for sale!" << endl;
		return 0;
	}
	else
	{
		m_amount = m_amount - n;
		m_sold = m_sold + n;
		float money = m_price * n; // The amount of money can get after solding 
		cout << n << " " << m_name << " are sold." << endl;
		return money;
	}
}

// Replensih item function
void Item::replenish(int n)
{
	if (n < 0)
	{
		cout << "Replenish amount must be bigger than 0!" << endl;
	}
	else
	{
		m_amount = m_amount + n;
		cout << n << " " << m_name << " are added to the stock." << endl;
	}
}

// Print all information of item (name, price, number of items and number of sold items)
void Item::printItem()
{
	cout << setw(size1) << m_name << setw(size) << m_price << setw(size) << m_amount << setw(size) << m_sold << endl;
}

void Item::setName(string name) { m_name = name; }

void Item::setPrice(float price) { m_price = price; }

void Item::setAmount(int amount) { m_amount = amount; }

void Item::setSold(int sold) { m_sold = sold; }

/*
    Operator overloading
*/
ostream &operator<<(ostream &out, const Item &i)
{
	out << i.m_name << endl
		<< i.m_price << endl
		<< i.m_amount << endl
		<< i.m_sold << endl;
	return out;
}

istream &operator>>(istream &in, Item &i)
{
	in >> i.m_name;
	in >> i.m_price;
	in >> i.m_amount;
	in >> i.m_sold;
	return in;
}