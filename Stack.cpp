// Lab #9
// CIS-2542-001
// Stack

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string file;																	// holds user input for file name
	ifstream myfile;																// holds file to open
	stack <char> pile;																// stack to hold curly braces
	char test;																		// variable to check each character in file
	int lineNum = 1;																// variable to hold line number
	bool error = false;																// variable to tell if an error was found
	bool open = false;																// variable tells if file was successfully opened

	const string Left = "{[(";														// variable to determine left side curly braces
	const string Right = "}])";														// variable to determine right side curly braces

	cout << "What file do you want to check: ";										// prompt user for file name
	cin >> file;

	cout << endl;

	myfile.open(file);																// open file

	if (myfile.is_open())															// if file opened successfully
	{
		open = true;																// file was opened

		while(!myfile.eof())														// repeat until the end of the file
		{
			myfile.get(test);														// move to the next charactor of the file

			if (!myfile.eof())														// if the file isn't empty
			{
				if(test==Left[0])													// if character is { add it to the stack
					pile.push(test);
				else if(test==Left[1])												// if character is [ add it to the stack
					pile.push(test);
				else if(test==Left[2])												// if character is ( add it to the stack
					pile.push(test);
				else if(test==Right[0])												// if character is }
				{
					if(!pile.empty() && pile.top()==Left[0])						// if the character matches previous curly brace then remove top of stack
						pile.pop();
					else
					{
						cout << "Error on line " << lineNum << endl;				// if the character doesn't match previous curly brace then report error on that line
						error = true;
					}
				}
				else if(test==Right[1])
				{
					if(!pile.empty() && pile.top()==Left[1])						// if the character matches previous curly brace then remove top of stack
						pile.pop();
					else
					{
						cout << "Error on line " << lineNum << endl;				// if the character doesn't match previous curly brace then report error on that line
						error = true;
					}
				}
				else if(test==Right[2])
				{
					if(!pile.empty() && pile.top()==Left[2])						// if the character matches previous curly brace then remove top of stack
						pile.pop();
					else
					{
						cout << "Error on line " << lineNum << endl;				// if the character doesn't match previous curly brace then report error on that line
						error = true;
					}
				}
				else if (test == '\n')												// when the end of each line is reached increase the line number variable
					lineNum ++;
			}
		}
		
		myfile.close();																// close file
	}
	else																			// if file failed to open
		cout << "Couldn't open file " << file << endl;								// prompt that file didn't open
		
	if (error == false && open==true)												// prompt if no errors were found
		cout << "No errors found" << endl;

	return EXIT_SUCCESS;
}

// Output
/*

What file do you want to check: input.cpp

Couldn't open file input.cpp
Press any key to continue . . .


What file do you want to check: input1.cpp

No errors found
Press any key to continue . . .


What file do you want to check: input2.cpp

Error on line 8
Press any key to continue . . .


What file do you want to check: input3.cpp

No errors found
Press any key to continue . . .


What file do you want to check: input4.cpp

Error on line 18
Error on line 23
Error on line 59
Press any key to continue . . .


What file do you want to check: input5.cpp

No errors found
Press any key to continue . . .


What file do you want to check: input6.cpp

Error on line 47
Error on line 49
Error on line 51
Press any key to continue . . .

*/