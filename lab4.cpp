// FILE: str_demo.cxx
// This is a small demonstration program showing how the string class is used.
#include <iostream>     // Provides cout and cin
#include "mystring.h"   // Or use the Standard Library <string>

using namespace std;
using namespace main_savitch_4;

void printString(main_savitch_4::string strCopy);
void testOperators();
void testBoolOperators();
void printResult(bool);
void testInput();

int main()
{
    cout << "Testing myString Class" << endl;

    testOperators();
    testBoolOperators();
    testInput();
    
    
    return EXIT_SUCCESS;
}

void testInput()
{
    main_savitch_4::string firstName, lastName, fullName;
    
    cout << "Enter Your First Name: ";
    cin >> firstName;
    
    cout << "Enter Your Last Name: ";
    cin >> lastName;
    
    cout << "Now Enter Your Full Name: ";
    cin.ignore();
    getline(cin, fullName, '\n');
    
    firstName += ' ';
    firstName += lastName;
    
    cout << "Entered Seperately: ";
    printString(firstName);
    
    cout << "Entered All At Once: ";
    printString(fullName);
    
    
    if (firstName == fullName)
        cout << "Those are equal" << endl;
    else 
        cout << "Those are NOT equal" << endl;
}

void printResult(bool b)
{
    if (b)
        cout << "Correct" << endl;
    else 
        cout << "Wrong" << endl;
}

void testBoolOperators()
{
    main_savitch_4::string name1("Paul"), name2("Paul Konerko"), name3("paul konerko"), name4("Paul");
    
    printResult(name1 == name4);
    printResult(name1 >= name4);
    printResult(name1 <= name4);
    printResult(name1 != name2);
    
    printResult(name1 != name2);
    printResult(name1 <= name2);
    printResult(name1 < name2);
    
    printResult(name3 != name1);
    printResult(name3 > name1);
    printResult(name3 >= name1);
    
    
}

void testOperators()
{
    main_savitch_4::string a, b, c;
    
    printString(a);
    
    char arr[] = "CIS 2542";
    for (int i=0; i<strlen(arr) + 1; i++)
        a += arr[i];
    
    printString(a);
    
    a += " Advanced ";
    printString(a);
    
    b = "C++ Programming";
    
    a += b;
    printString(a);
    
    c = a;
    printString(c);
    
    cout << "Printing using operator []" << endl;
    for (int i=0; i<c.length(); i++)
        cout << c[i];
    
    cout << endl;

}

void printString(main_savitch_4::string strCopy)
{
    cout << "String = " << strCopy << ", size = " << strCopy.length() << endl;
}
