#include <iostream>
#include <string>
using namespace std;

class Item
{
public:
	Item(string name = "", float price = 0.0, int amount = 0, int sold = 0);
	Item(const Item &i);
	string getName() const;
	float getPrice() const;
	int getAmount() const;
	int getSold() const;
	float sell(int n);
	void add(int n);
	void printItem();
	void setName(string name);
	void setPrice(float price);
	void setAmount(int amount);
	void setSold(int sold);
	friend ostream &operator<<(ostream &out, const Item &i);
	friend istream &operator>>(istream &in, Item &i);

private:
	string m_name; // Name of item
	float m_price; // Price of item
	int m_amount; // Number of items he has for sale
	int m_sold; // Number of items sold
};