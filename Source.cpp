
// Lab #5
// source file

#include <iostream>
#include "node1.h"

using namespace std;
using namespace main_savitch_5;


// function prototypes
node * splitLT(const node*, int);
node * splitGTE(const node*, int);
void printList(const node*);
void sort_list(node*&);

int main()
{
	node* a = NULL;																			// list to test on
	node * newListLT = NULL;																// list that uses splitLT
	node * newListGTE = NULL;																// list that uses splitGTE
	int splittingValue = 21;																// test splittingValue

	// insert values into links in the list a
	list_head_insert(a, 15);											
	list_head_insert(a, 25);
	list_head_insert(a, 17);
	list_head_insert(a, 21);
	list_head_insert(a, 17);
	list_head_insert(a, 6);
	list_head_insert(a, 42);

	cout << "This is the main list" << endl;												// makes output look nice

	printList(a);																			// print list a

	cout << "The splitting Value is " << splittingValue << endl;							// makes output look nice
	cout << endl;																			// makes output look nice

	cout << "This is the new list using splitLT" << endl;									// makes output look nice

	newListLT = splitLT(a, splittingValue);													// create newListLT by using splitLT on a
	
	printList(newListLT);																	// print list newListLT

	cout << "This is the new list using splitGTE" << endl;									// makes output look nice

	newListGTE = splitGTE(a, splittingValue);												// create newListGTE by using splitGTE on a

	printList(newListGTE);																	// print list newListGTE

	sort_list(a);																			// sort list a using sort_list
	
	cout << "This is the list sorted using sort_list()" << endl;							// makes output look nice
	cout << endl;																			// makes output look nice

	printList(a);																			// print list a which is now pointed to a new list

	cout << endl;																			// makes output look nice

	return EXIT_SUCCESS;
}

// This function will return a pointer to a new list
// containing all values LESS THAN the splitting value.
// The original list remains unchanged.
node * splitLT(const node* oldList, int splittingValue)
{
	node* newList = NULL;																	// create new list to hold links
	const node* p;																			// pointer to hold position in list 

	for (p = oldList; p != NULL; p = p->link())												// loop to find links that are less then splittingValue and insert them in newList
	{
		if (p->data() < splittingValue)
			list_head_insert(newList, p->data());
	}

	return newList;																			// return new list of less than values
}

// This function will return a pointer to a new list
// containing all values GREATER THAN OR EQUAL TO the
// splitting value. The original list remains unchanged.
node * splitGTE(const node* oldList, int splittingValue)
{
	node* newList = NULL;																	// create new list to hold links
	const node* p;																			// pointer to hold position in list

	for (p = oldList; p != NULL; p = p->link())												// loop to find links that are greater than or equal to splittingValue and insert them in newList
	{
		if (p->data() >= splittingValue)
			list_head_insert(newList, p->data());
	}

	return newList;																			// return new list of greater than or equal values
}

// THis functgion will print all values in a list given
// a starting node
void printList(const node* list)
{
	const node* p;																			// pointer to hold position in list
	int place = 1;																			// number to make output look nicer

	for (p = list; p != NULL; p = p->link(), place++)										// loop to print out each link in list
		cout << "The " << place << " value in the list is " << p->data() << endl;

	cout << "End of list" << endl;															// makes output look nice
	cout << endl;																			// makes output look nice
}

// Precondition: head_ptr is a head pointer of
// a linked list of links, and these links can be
// compared with a less-than operator.
// Postcondition: head_ptr points to the head
// of a linked list with exactly the same entries
// (including repetitinos if any), but the entries
// in this listare sorted from smallest to largest. 
// The original linked list is no longer available.
void sort_list(node*& head_ptr)
{
	node* test;																				// pointer to mark link in list that is being tested
	node* prev;																				// pointer to mark link before the one being tested
	node* biggest;																			// pointer to mark link that is the biggest in the list
	node* biggestPrev = head_ptr;															// pointer to mark link before the one that is the biggest
	node* newList = NULL;																	// pointer to new list that will be sorted

	while (head_ptr != NULL)																// loop that checks if there is links in the list
	{
		biggest = head_ptr;																	// set first link as biggest
		test = head_ptr->link();															// set test as the second link
		prev = head_ptr;																	// set prev as link before test

		while (test != NULL)																// loop to find biggest link (only if test is a valid link
		{
			if (biggest->data() < test->data())												// check if test value is bigger then biggest value
			{
				biggest = test;																// change biggest link to test link
				biggestPrev = prev;															// change biggestPrev to new link before new biggest
			}

			// shift prev and test to next links
			prev = test;
			test = test->link();
		}

		if (biggest == head_ptr)															// if biggest link was the first link				
			head_ptr = head_ptr->link();														// point head_ptr to next link
		else																				// if biggest was a link after first link
			biggestPrev->set_link(biggest->link());												// point biggestPrev to the link following biggest

		list_head_insert(newList, biggest->data());											// insert biggest value into new list
	}

	head_ptr = newList;																		// point head_ptr to newList
}


/*

Output for Problem 6 + 7

This is the main list
The 1 value in the list is 42
The 2 value in the list is 6
The 3 value in the list is 17
The 4 value in the list is 21
The 5 value in the list is 17
The 6 value in the list is 25
The 7 value in the list is 15
End of list

The splitting Value is 21

This is the new list using splitLT
The 1 value in the list is 15
The 2 value in the list is 17
The 3 value in the list is 17
The 4 value in the list is 6
End of list

This is the new list using splitGTE
The 1 value in the list is 25
The 2 value in the list is 21
The 3 value in the list is 42
End of list

This is the list sorted using sort_list()

The 1 value in the list is 6
The 2 value in the list is 15
The 3 value in the list is 17
The 4 value in the list is 17
The 5 value in the list is 21
The 6 value in the list is 25
The 7 value in the list is 42
End of list


Press any key to continue . . .

*/