#ifndef INS_H
#define INS_H

#include "ins.h"
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

// Print menu function
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
			float price;
			int amount;
			while (true)
			{
				cout << "Enter price (float): ";
				cin >> price;

				// Check boundary
				if (cin.fail())
				{
					cout << "The price must be a float!" << endl;
					cin.clear(); // Clear the error flag on cin
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
				}
				else
				{
					break;
				}
			}
			while (true)
			{
				cout << "Enter amount (integer): ";
				cin >> amount;

				// Check boundary
				if (cin.fail())
				{
					cout << "The amount must be an integer!" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
				{
					break;
				}
			}
			stock->addItem(item, price, amount); // Add all information of an item to an array
			printInstruction();
		}

		else if (command == "2")
		{
			cout << "What item: ";
			string item;
			getline(cin, item);
			int number;
			while (true)
			{
				cout << "Enter amount you want to sell: ";
				cin >> number;

				// Check boundary
				if (cin.fail())
				{
					cout << "The amount must be an integer!" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
				{
					break;
				}
			}
			stock->Sell(item, number); // Sell an item with particular amount
			this->printInstruction();
		}
		else if (command == "3")
		{
			cout << "What item: ";
			string item;
			getline(cin, item);
			int number;
			while (true)
			{
				cout << "Enter amount you want to replenish: ";
				cin >> number;

				// Check boundary
				if (cin.fail())
				{
					cout << "The amount must be an integer!" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
				{
					break;
				}
			}
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