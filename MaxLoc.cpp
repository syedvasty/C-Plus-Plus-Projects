
// Lab #6 maxLoc()
// source file

#include <iostream>
#include <list>

using namespace std;

// function prototypes
template <typename T>
typename list<T>::iterator maxLoc(list<T>&);

int main()
{
	int intArr[] = {23, 49,-3, 29, 17, 200, 38, 93, 40};						// create an array of int's
	int intSize = sizeof(intArr) / sizeof(int);									// intSize is the size of the int array
	list<int> intList(intArr, intArr+intSize);									// intList is made up of the elements from intArr

	char chrArr[] = "Hello World!";												// create an array of chr's
	int chrSize = sizeof(chrArr);												// chrSize is the size of the char array
	list<char> chrList(chrArr, chrArr+chrSize);									// chrSize is made up of the elements from chrArr

	list<int>::iterator iterInt;												// creates iterator to be used with intList
	list<char>::iterator iterChr;												// creates iterator to be used with chrArr

	cout << "This is the intList" << endl;										// makes output look better
	
	for (iterInt = intList.begin();iterInt != intList.end(); iterInt++)			// prints out the intList elements
		cout << *iterInt << endl;

	cout << endl;																// makes output look better
	cout << "This is the chrList" << endl;										// makes output look better

	for (iterChr = chrList.begin();iterChr != chrList.end(); iterChr++)			// prints out the chrList elements
		cout << *iterChr << endl;

	cout << "This is what maxLoc() looks like on the two lists" << endl;		// makes output look better
	cout << endl;																// makes output look better

	while (intSize != 0)														// finds and outputs the largest value in the intList then deletes that value and continues till the list is empty
	{
		iterInt = maxLoc(intList);
		cout << *iterInt << endl;
		intList.erase(iterInt);
		intSize--;
	}

	cout << endl;																// makes output look better

	while (! chrList.empty())													// finds and outputs the largest value in the chrList then deletes that value and continues till the list is empty
	{
		iterChr = maxLoc(chrList);
		cout << *iterChr << endl;
		chrList.erase(iterChr);
		chrSize--;
	}


	return EXIT_SUCCESS;
}

template <typename T>
typename list<T>::iterator maxLoc (list<T>& aList)								// finds highest element and returns it using an iterator
{
	list<T>::iterator iter;														// iterator to check each element in the list
	list<T>::iterator highest = aList.begin();									// iterator to hold the highest element in the list

	iter = aList.begin();														// set the iter to start at the first element in the list
	iter++;

	for (iter; iter != aList.end(); iter++)										// loop to find the largest element in the list
	{
		if (*iter > *highest)
			highest = iter;
	}

	return highest;																// return the largest element
}


// output

/*
This is the intList
23
49
-3
29
17
200
38
93
40

This is the chrList
H
e
l
l
o

W
o
r
l
d
!

This is what maxLoc() looks like on the two lists

200
93
49
40
38
29
23
17
-3

r
o
o
l
l
l
e
d
W
H
!


Press any key to continue . . .

*/