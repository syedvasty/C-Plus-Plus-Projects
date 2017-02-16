// Chapter #1
// January 26, 2015
#include <iostream>
#include <cassert>																		// assert statements

using namespace std;

float divide(int, int);

enum dayOfWeek																			// enumeration declaration
{
	SUNDAY,			// = 0
	MONDAY,			// = 1
	TUESDAY,		// = 2
	WEDNESDAY,		// = 3
	THURSDAY,		// = 4
	FRIDAY,			// = 5
	SATURDAY		// = 6
};

int main()
{
	dayOfWeek today;
	
	today = MONDAY;
	
	if (today == MONDAY)
		cout << "We have class at 6:00 to 10:05 if anyone asks" << endl;

	cout << "today = " << today << endl;												// integer = 1
	
	float value;

	try
	{
		value =  divide(5, 2);

		cout  << "value = " << value << endl;
	}
	catch (domain_error err)
	{
		cout << err.what() << endl;
	}
/*	catch (int errCode)
	{
		cout << "Divide failed with code " << errCode << endl;
	}	
	catch (char *msg)
	{
		cout << "Divide failed -- " << msg << endl;
	}	
*/

	return EXIT_SUCCESS;															//return 0 if success
}

float divide(int numerator, int denominator)
{
	// precondition: denominator cannot be zero
/*	assert(denominator != 0);														// crash program if this

	if (denominator == 0)
		throw -1;																	// throw int or text "--------"

	if (denominator == 2)
		throw "this is the wrong denominator";
*/
	if (denominator == 0)
		throw domain_error("Denominator must not be zero");
			
	return float(numerator) / denominator;

}