// Lab #8
// CIS-2542-001
// Hash Table

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct book {																								// struct to hold each book's information
	int bookId;
	string title;
	string author;
	float cost;
	float price;
	int quantity;
};

// Function Prototypes
void loadTable(book [], int);
int getHashKey(int, int);
void loadBook(book [], book, int);
void printBook(book);
void clearTable(book [], int);
void placeOrder(book [], int);
int menu();

int main()
{
	int input, option;																						// input is used to hold size of table while option is what you choose from the menu
	book *test;																								// book pointer to hold position of book array 
	char repeat = 'y';

	cout << "Enter the size of the hash table: ";																				
	cin >> input;																							// ask for the size of the table

	test = new book[input];																					// create test array table to hold all the books

	clearTable(test, input);																				// sets all the bookId's for the books in the table to -1 
	loadTable(test, input);																					// adds all of the books from the txt file to the table

	while (repeat == 'y')																					// repeat this until user says exit
	{
		option = menu();																					// get input from menu()

		if (option == 1)
			placeOrder(test, input);																		// call placeOrder()
		else
			repeat = 'n';																					// stops loop
	}

	delete [] test;																							// delete test array table at program close

	return EXIT_SUCCESS;
}

void loadTable (book table [], int size)																	// populates the table with the books from the txt file
{
	int amount = 0;																							// amount holds the number of books added to the table
	book temp;																								// holds each book information before it is added to the table
	string costTemp, idTemp, titleTemp, authorTemp, priceTemp, quantityTemp;								// strings to hold data for each part of the book from the txt file

	ifstream myfile;																						// opens inventory.txt file to read from
	myfile.open ("inventory.txt");

	while(!myfile.eof() && amount < size)																	// loop to read in all of the data from each book in the txt file and call loadBook to add them to the table
	{
		getline(myfile, idTemp, '#');																		// get each part of the book and put them in their corresponding temp variables
		getline(myfile, titleTemp, '#');
		getline(myfile, authorTemp, '#');
		getline(myfile, costTemp, '#');
		getline(myfile, priceTemp, '#');
		getline(myfile, quantityTemp);
		
		temp.bookId = stoi (idTemp);																		// convert and insert data parts into a book
		temp.title = titleTemp;
		temp.author = authorTemp;
		temp.cost = stof (costTemp);
		temp.price = stof (priceTemp);
		temp.quantity = stoi (quantityTemp);

		loadBook(table, temp, size);																		// loadBook() called to insert book into table
		
		amount++;																							// increase book amount to keep track of number of books in table
	}

	cout << "Loaded " << amount << " books" << endl;														

	myfile.close();																							// close file after finished reading it
}

int getHashKey (int value, int size)																		// returns a key using value % size
{
	int key;

	key = value % size;
	
	return key;
}

void loadBook (book table [], book pres, int size)															// adds a book to the table
{
	int key, value = 25, count = 0;																			// key holds hash key, value is the value used in getHashKey(), count adds up number of collisions

	key = getHashKey(value, size);																			// get a hash key

	while (table[key].bookId != -1)																			// loop to check each position in table if the present spot is not empty
	{
		key = (key + 1) % size;																				// increment key to the next spot in table

		if (table[key].bookId != -1)																		// Outputs that there was a collision
		{
			cout << "Collision " << count << endl;
			count++;
		}
	}

	table[key] = pres;																						// insert the book into the table after the loop found an open spot
}

void printBook (book table)																					// prints out the data for a book
{
	cout << "Book ID:     " << table.bookId << endl;													
	cout << "Title:       " << table.title << endl;
	cout << "Author:      " << table.author << endl;
	cout << "Cost:        " << table.cost << endl;
	cout << "Price:       " << table.price << endl;
	cout << "Quantity:    " << table.quantity << endl;
}

void clearTable (book table [], int size)																	// sets each bookId of all books in the table to -1
{
	for (int i=0; i<size; i++)
		table[i].bookId = -1;
}

void placeOrder (book table [], int size)																	// find a book and if found get quantity and process the order
{
	int ID, key, value = 25, quantity, count = 0;		// ID holds book id#, key holds hash key, value holds value used in hash key creation, quantity holds quantity of book, count holds value to decide if book ID is real
	float total, profit;																					// total holds total of order, profit holds profit of order
	bool accept = false;																					// accept keeps loop going when the quantity is invalid 

	cout << "Enter Book ID #: ";																			
	cin >> ID;																								// enter book id #

	key = getHashKey(value, size);																			// get hash key to help looking up books

	while (table[key].bookId != ID && count < size)															// loop to find book that has the ID entered
	{
		key = (key + 1) % size;
		count++;
	}

	if (table[key].bookId == ID)																			// if book is found
	{
		printBook(table[key]);																				// print the book's information
		
		cout << "*** Looked at " << count << " records ***" << endl;										// print out the # of records looked at

		cout << "Enter quantity desired: ";
		cin >> quantity;																					// quantity of book to order

		while (accept == false)																				// loop to make sure quantity is valid
		{
			if (quantity <= table[key].quantity)															// if quantity is valid
			{
				total = table[key].price * quantity;														// calculate total
				profit = total - (table[key].cost * quantity);												// calculate profit

				cout << "Order Total: " << total << endl;													// printout total and profit
				cout << "Order Profit: " << profit << endl;

				table[key].quantity = table[key].quantity - quantity;										// calculate new quantity and replace the old one with the new quantity
				accept = true;																				// set that quantity was accepted
			}
			else																							// if quantity isn't valid
			{
				cout << "Invalid Quantity" << endl;
				cout << "Try Again: ";
				cin >> quantity;																			// retype quantity
			}
		}
	}
	else																									// if book isn't found
		cout << "Book is not found" << endl;												
}

int menu ()																									// menu to get option from user
{
	int option;																								// option holds input form user
	
	cout << "1. Place Order" << endl;
	cout << "2. Exit" << endl;
	cout << "Enter choice: ";
	cin >> option;																							// get option from user

	return option;
}

/*
Output


Collision 96
Collision 97
Collision 98
Collision 99
Loaded 102 books
1. Place Order
2. Exit
Enter choice: 1
Enter Book ID #: 111111
Book is not found
1. Place Order
2. Exit
Enter choice: 1
Enter Book ID #: 111272
Book ID:     111272
Title:       The Iliad
Author:      Homer
Cost:        2.78
Price:       9.99
Quantity:    10
*** Looked at 21 records ***
Enter quantity desired: 2
Order Total: 19.98
Order Profit: 14.42
1. Place Order
2. Exit
Enter choice: 1
Enter Book ID #: 111272
Book ID:     111272
Title:       The Iliad
Author:      Homer
Cost:        2.78
Price:       9.99
Quantity:    8
*** Looked at 21 records ***
Enter quantity desired: 10
Invalid Quantity
Try Again: 3
Order Total: 29.97
Order Profit: 21.63
1. Place Order
2. Exit
Enter choice: 2
Press any key to continue . . .

*/