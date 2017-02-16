//By Syed Vasty
//Assignment # 3

#include<iostream>

using namespace std;

//functions
int max(int[], int);
int min(int[], int);
int arraySum(int[], int);
void sortInAscendingOrder(int[], int);
void sortinDecendingOrder(int[], int);


int main()
{
	//This variables defines the size of the array
	int const size = 5;
	//Defining the array
	int elements[size];

	//Asking the user to input the elements into the array
	cout << "Enter "<<size<<" numbers : " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> elements[i];
	}

	//Passing the value to the function and storing the result into a variable
	int maximum = max(elements, size);
	int minimum = min(elements, size);
	int Sum = arraySum(elements, size);
	//Printing the Result
	cout << "The max value from the array is : " << maximum << endl;
	cout << "The min value from the array is : " << minimum << endl;
	cout << "The sum of the array is : " << Sum << endl;
	cout << "***Sorting the Array in Ascending Order***" << endl;
	sortInAscendingOrder(elements, size); //Function to sort the array in Ascending Order
	cout << "***Sorting the Array in Descending Order***" << endl;
	sortinDecendingOrder(elements, size); //Function to sort the array in descending Order.
	
	
	system("pause");
	return 0;
}

//This function will find the max value from the array
int max(int arrayElem[], int size)
{
	int max= arrayElem[0];
	for (int i = 0; i < size; i++)
	{
		if (arrayElem[i] > max)
		{
			max = arrayElem[i];
		}
	}
	return max;
}

//This function will find the min value from the array
int min(int arrayElem[], int size)
{
	int min = arrayElem[0];
	for (int i = 0; i < size; i++)
	{
		if (arrayElem[i] < min)
			min = arrayElem[i];
	}
	return min;
}
//This function will find the sum of the array
int arraySum(int arrayElem[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arrayElem[i];
	}
	return sum;
}
/**
This function will sort the array in Ascending order 
and will print the result on the screen
**/
void sortInAscendingOrder(int arrayElem[], int size)
{
	int temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arrayElem[j] < arrayElem[i])
			{
				temp = arrayElem[i];
				arrayElem[i] = arrayElem[j];
				arrayElem[j] = temp;
			}
		}
		
	}
	for (int i = 0; i < size; i++)
	{
		cout << arrayElem[i] << endl;
	}
	
}

/**
This function will sort the array in decending order
and will print the result on the screen
**/
void sortinDecendingOrder(int arrayElem[], int size)
{
	int temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arrayElem[j] > arrayElem[i])
			{
				temp = arrayElem[j];
				arrayElem[j] = arrayElem[i];
				arrayElem[i] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << arrayElem[i] << endl;
	}
}

/**
***RESULT***
Enter 5 numbers :
5
4
2
3
1
The max value from the array is : 5
The min value from the array is : 1
The sum of the array is : 15
***Sorting the Array in Ascending Order***
5
4
3
2
1
***Sorting the Array in Descending Order***
1
2
3
4
5
Press any key to continue . . .**/