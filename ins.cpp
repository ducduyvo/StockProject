#ifndef INS_H
#define INS_H

#include "ins.h"
#include <type_traits>
#endif

/*
    Constructor
*/
Instruction::Instruction()
{
	stock = new Stock();
}

/*
    Deconstructor
*/
Instruction::~Instruction()
{
	delete stock;
}

// Guidex all the option for user 
void Instruction::printInstruction()
{
	cout << "\n";
	cout << "****************************************" << endl;
	cout << "Stock program / Choose your option:" << endl;
	cout << "	|1. Add new item|" << endl;
	cout << "	|2. Sell an item|" << endl;
	cout << "	|3. Replenish stock|" << endl;
	cout << "	|4. Find items|" << endl;
	cout << "	|5. Load list of item|" << endl;
	cout << "	|6. Save list of item|" << endl;
	cout << "	|7. Print items and revenue|" << endl;
	cout << "	|8. Clear the list|" << endl;
	cout << "	|9. Clear the disk|" << endl;
	cout << "	|x. Exit|" << endl;
	cout << "****************************************" << endl
		 << endl;
}

template <typename T>
// Function for getting right value
T run_function(string message, string name, T number)
{
	while (true)
	{
		cout << message;
		cin >> number;
		if (cin.fail()) // detects whether the value entered fits the value defined in the variable
		{
			if (is_same<T, int>::value) // Check number is integer or not
			{
				cout << "The " << name << " must be integer!" << endl;
			}
			else if (is_same<T, float>::value) // Check number is float or not
			{
				cout << "The " << name << " must be float!" << endl;
			}
			else
			{
				cout << "The input is not correct!";
			}
			cin.clear();										 // Clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
		}
		else
		{
			break;
		}
	}
	return number;
}

// Function to choose option for main program
void Instruction::handleCommand()
{
	while (true)
	{
		string command;
		cout << "Enter command: ";
		cin >> command;
		cin.ignore();
		if (command == "1")
		{
			string item;
			cout << "What item: ";
			getline(cin, item);
			float price = 0.0;
			int amount = 0;
			price = run_function("Enter price (float): ", "price", price);
			amount = run_function("Enter amount (integer): ", "amount", amount);
			stock->addItem(item, price, amount); // Add all information of an item to an array
			printInstruction();
		}

		else if (command == "2")
		{
			cout << "What item: ";
			string item;
			getline(cin, item);
			int number = 0;
			number = run_function("Enter amount you want to sell: ", "number", number);
			stock->Sell(item, number); // Sell an item with particular amount
			this->printInstruction();
		}
		else if (command == "3")
		{
			cout << "What item: ";
			string item;
			getline(cin, item);
			int number = 0;
			number = run_function("Enter amount you want to sell: ", "number", number);
			stock->Replenish(item, number); // Replenish an item with particular amount
			this->printInstruction();
		}

		else if (command == "4")
		{
			string item;
			cout << "Enter keyword: ";
			getline(cin, item);
			stock->Find(item);
			this->printInstruction();
		}
		else if (command == "5")
		{
			ifstream myStock("myStock.txt");
			if (myStock.is_open())
			{

				myStock >> *stock; // Using overloading >> operator to read all the items from disk
				myStock.close();
				cout << "List is loaded from disk." << endl;
			}
			else
			{
				cout << "Unable to open file";
			}
			this->printInstruction();
		}

		else if (command == "6")
		{
			ofstream myStock("myStock.txt");
			if (myStock.is_open())
			{
				myStock << *stock; // Write (save) all the items to disk
				myStock.close();
				cout << "List is saved to disk." << endl;
			}
			else
			{
				cout << "Unable to open file";
			}
			this->printInstruction();
		}

		else if (command == "7")
		{
			stock->printList(); // Print all the information of all items
			this->printInstruction();
		}

		else if (command == "8")
		{
			stock->Clear(); // Clear an array of item
			cout << "All items are cleared." << endl;
			this->printInstruction();
		}
		else if (command == "9")
		{
			ofstream ofs("myStock.txt", ios::out | ios::trunc); // Clear the content in the file
			cout << "The disk is cleared.";
			this->printInstruction();
		}
		else if (command == "x") // Exit the program function
		{
			break;
		}
		else
		{
			cout << "You typed wrong command. Please follow our Instruction!" << endl;
		}
	}
}