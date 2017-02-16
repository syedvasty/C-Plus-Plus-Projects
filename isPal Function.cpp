// Lab #7
// CIS-2542-001
// Problem #5
// isPal function

#include <iostream>
#include <string>

using namespace std;

//function prototypes
double sumover(unsigned int n);
bool isPal (const string& str, int startIndex, int endIndex);
int main()
{
	unsigned int n;																					// variable to hold number of integers for the sumover function
	double answer = 0.0;																			// variable to hold answer to sumover function
	const string& str = {"level"};																	// variable to hold string for isPal function
	int startIndex = 0, endIndex = 5;																// variables to hold the starting and ending positions for str string
	bool pal = true;																				// variable to hold value from isPal function

	n = 290;																						

	answer = sumover(n);																			// find answer for sumover with n of 290

	cout << "The recursive function (with n of " << n << ") answer is: " << answer << endl;			// makes the output look good

	pal = isPal(str, startIndex, endIndex);															// test str string using isPal

	cout << "Value of isPal bool: " << pal << endl;													// makes the output look good

	return EXIT_SUCCESS;
}

double sumover(unsigned int n)
{
	if (n==0)																						
		return 0;																					// sumover with n of 0 = 0
	else
		return (1.0/n) + (sumover(n-1));															// recursion code to repeat sumover to add up 1/n for each n

}

bool isPal(const string& str, int startIndex, int endIndex)
{
	if (startIndex >= endIndex -1)		return true;																				// if string is a palindrome
	else if (str[startIndex] != str[endIndex-1])
		return false;																				// if string isn't a palindrome
	else
	{
		startIndex++;																				// increment starting and ending positions to check next characters
		endIndex--;

		return isPal(str, startIndex, endIndex);													// recursion code to repeat isPal to check next characters
	}
}

// output
/*

The recursive function (with n of 290) answer is: 6.24882
Value of isPal bool: 1
Press any key to continue . . .

*/