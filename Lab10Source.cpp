// Assignment 10
// Lab10Source.cpp

#include <iostream>
#include "vpqueue.h"

using namespace std;
using namespace lab;

int main()
{
	int arr[5] = {6, 2, 3, 5, 3};				// list of ints to put into queue
	vpriority_queue<int> pq;					// create priority queue to hold the list
	int i;										// variable to hold position

	for (i=0; i<5; i++)							// loop to input list elements into the priority queue
		pq.push(arr[i]);

	cout << pq.top() << " ";					// print out highest priority element
	pq.pop();									// removes highest priority element from the queue

	cout << pq.top() << " ";					// print out highest priority element
	pq.pop();									// removes highest priority element from the queue

	pq.push(10);								// add an element to the queue

	pq.push(1);									// add an element to the queue

	cout << pq.top() << " ";					// print out highest priority element
	pq.pop();									// removes highest priority element from the queue

	cout << pq.top() << " ";					// print out highest priority element
	pq.pop();									// removes highest priority element from the queue

	return EXIT_SUCCESS;
}

/*

Output

6 5 10 3 Press any key to continue . . .

*/