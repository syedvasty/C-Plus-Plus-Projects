#include <iostream>
#include "d_date.h"

using namespace std;


// function prototypes																		added these prototypes
bool operator==(date, date);
bool operator!=(date, date);


void main (void)
{
	date date1;
	date date2;

	cout << "Enter date1 and date2:" << endl;

	while (cin >> date1 >> date2)
	{
		cout << "Printing date1 and date2" << endl;
		cout << date1 << endl << date2 << endl;

		if (date1 == date2) 
			cout << date1 << " is equal to " << date2 << endl;

		if (date1 != date2) 
			cout << date1 << " is not equal to " << date2 << endl;

		if (date1 < date2) 
			cout << date1 << " is less than " << date2 << endl;

		if (date1 > date2) 
			cout << date1 << " is greater than " << date2 << endl;

		++date1;
		++date2;

		cout << "Increment of date1: " << date1 << endl;
		cout << "Increment of date2: " << date2 << endl;

		cout << endl << "---End of Run---" << endl << endl;

		cout << "Enter date1 and date2:" << endl;
	}

}

bool operator==(date lhs, date rhs)												// function to compare dates and say that they are the same
{
	return (lhs.getMonth() == rhs.getMonth() &&
		lhs.getDay() == rhs.getDay() &&
		lhs.getYear() == rhs.getYear());
}

bool operator!=(date lhs, date rhs)												// function to compare dates and say that they are different
{
	return !(lhs == rhs);
}


/*

output

Enter date1 and date2:
5/5/1977
10/24/1973
Printing date1 and date2
5/5/1977
10/24/1973
5/5/1977 is not equal to 10/24/1973
5/5/1977 is greater than 10/24/1973
Increment of date1: 5/6/1977
Increment of date2: 10/25/1973

---End of Run---

Enter date1 and date2:
2/25/1944
9/30/1982
Printing date1 and date2
2/25/1944
9/30/1982
2/25/1944 is not equal to 9/30/1982
2/25/1944 is less than 9/30/1982
Increment of date1: 2/26/1944
Increment of date2: 10/1/1982

---End of Run---

Enter date1 and date2:
3/5/1999
3/7/1999
Printing date1 and date2
3/5/1999
3/7/1999
3/5/1999 is not equal to 3/7/1999
3/5/1999 is less than 3/7/1999
Increment of date1: 3/6/1999
Increment of date2: 3/8/1999

---End of Run---

Enter date1 and date2:
3/5/1999
3/5/1999
Printing date1 and date2
3/5/1999
3/5/1999
3/5/1999 is equal to 3/5/1999
Increment of date1: 3/6/1999
Increment of date2: 3/6/1999

---End of Run---

Enter date1 and date2:


*/