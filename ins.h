#ifndef ITEM_H
#define ITEM_H

#include "Item.h"
#endif

#ifndef STOCK_H
#define STOCK_H

#include "stock.h"
#endif

#include <iostream>
#include <string>
using namespace std;

class Instruction
{
public:
	Instruction();
	~Instruction();
	void printInstruction();
	void handleCommand();
private:
	Stock *stock; 
};