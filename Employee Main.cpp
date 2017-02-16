#include <iostream>
#include "emp.h"

using namespace std;

void main (void)
{
//	employee e("Timothy", "444-33-222");
//	e.displayEmployeeInfo();
//	
//	cout << endl;

	salaryEmployee sEmp("Louis","111-22-3333",800);
	hourlyEmployee hEmp("John","222-33-4444",19.50,40);

	sEmp.displayEmployeeInfo();
	cout << endl << endl;
	hEmp.displayEmployeeInfo();
	cout << endl << endl;



	//Call displayEmployeeInfo for base class
	sEmp.employee::displayEmployeeInfo();
	cout << endl;
	hEmp.employee::displayEmployeeInfo();
	cout << endl;

	//Copy derived class to base class
	employee e("Timothy", "444-33-222");

	e = hEmp; // ?

	e.displayEmployeeInfo();
	cout << endl;															// you can copy derived class to base class

	//Copy base class to derived class
//	sEmp = e; // ?
	
	
	
	// you have to overload = but normally don't do
	//Consider a pointer
/*
	employee *p;

	p = &e;
//	p = &sEmp;

	p->displayEmployeeInfo();
	cout << endl;
*/	
	employee *myStaff[3] = {&sEmp, &hEmp, &e};

	for (int i=0; i<3; i++)
	{
		myStaff[i]->displayEmployeeInfo();
		cout << endl;
	}

	//Constructors/Destructors
/*
	employee *p = new salaryEmployee("asdf", "asdf", 1234);

	delete p;
*/
	//Abstract Classes
//	employee e("Test", "1234");

	hourlyEmployee hEmp("Louis", "1234", 12, 34);						// after adding functions to satisfy abstract function this becomes possible	

}