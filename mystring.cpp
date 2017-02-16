
// implementation

#include "mystring.h"			

using namespace std;

namespace main_savitch_4
{
	// CONSTRUCTOR for the string class:
	//   string(const char str[ ] = "") -- default argument is the empty string.
	//     Precondition: str is an ordinary null-terminated string.
	//     Postcondition: The string contains the sequence of chars from str.

	string::string(const char str[])
	{
		current_length = strlen(str);												// set current_length to length of str string
		allocated = current_length + 1;												// set allocated to current_length plus one
		sequence = new char [allocated];											// set sequence to a new dynamic char array initialized to allocated size
		strcpy (sequence, str);														// copies str string into sequence
	}

	// copy constructor

	string::string(const string& source)
	{
		allocated = source.allocated;												// set allocated to allocated of source
		current_length = source.current_length;										// set current_length to source current_length
		sequence = new char[allocated];												// set sequence to a new dynamic char array initialized to allocated size
		strcpy (sequence, source.sequence);											// copies source sequence into new sequence
	}

	// destructor

	string::~string()
	{
		delete [] sequence;															// clears up memory from old sequence
	}


	//   char operator [ ](size_t position) const
	//     Precondition: position < length( ).
	//     Postcondition: The value returned is the character at the specified
	//     position of the string. A string's positions start from 0 at the start
	//     of the sequence and go up to length( )-1 at the right end.

	char string::operator [](size_t position) const
	{
		return sequence[position];													// returns the char at a position in the sequence
	}


	// MODIFICATION MEMBER FUNCTIONS for the string class:
	//   void operator +=(const string& addend)
	//     Postcondition: addend has been catenated to the end of the string.

	void string::operator +=(const string& addend)
	{
		if (current_length + addend.current_length > allocated - 1)					// check to make sure that the new concatenated sequence wont be bigger than the allocated space of the first sequence
			reserve(current_length + addend.current_length + 10);					// if it is then call reserved and give it a size of both the original sequences combined plus 10 more char's

		strcat(sequence, addend.sequence);											// concatenate both sequences into the first sequence

		current_length = strlen(sequence);											// set current_length of new concatenated sequence 
	}


	//   void operator +=(const char addend[ ])
	//     Precondition: addend is an ordinary null-terminated string.
	//     Postcondition: addend has been catenated to the end of the string.

	void string::operator +=(const char addend[])
	{
		if (current_length + strlen(addend) > allocated - 1)						// check to make sure that the new concatenated sequence wont be bigger than the allocated space of the first sequence
			reserve (current_length + strlen(addend) + 10);							// if it is then call reserved and give it a size of both the original sequences combined plus 10 more char's

		strcat(sequence, addend);													// concatenate both sequences into the first sequence

		current_length = strlen(sequence);											// set current_length of the new concatenated sequence
	}


	//   void operator +=(char addend)
	//     Postcondition: The single character addend has been catenated to the
	//     end of the string.

	void string::operator +=(const char addend)
	{
		if (current_length + 1 > allocated - 1)										// check to make sure that the new concatenated sequence wont be bigger than the allocated space of the first sequence
			reserve (current_length + 1 + 10);										// if it is then call reserved and give it a size of both the original sequence and the char combined plus 10 more char's

		sequence[current_length] = addend;											// concatenate the char to the end of the sequence
		sequence[current_length + 1] = NULL;										// add a null char to the end of the sequence

		current_length = current_length + 1;										// set current_length of the new concatenated sequence
	}


	//   void reserve(size_t n)
	//     Postcondition: All functions will now work efficiently (without
	//     allocating new memory) until n characters are in the string.

	void string::reserve(size_t n)
	{
		char *nseq;																	// create a temp pointer to hold the place of the old sequence when its pointer is deleted

		if (n < current_length + 1)													// change the allocated size of the sequence to match the new size specified by n
			n = allocated;

		nseq = new char [n];														// create a new char array with a size of n
		strcpy(nseq, sequence);														// copy old sequence into new bigger sequence
		delete [] sequence;															// delete old sequence array
		sequence = nseq;															// set the old sequence pointer to new bigger sequence
		allocated = n;																// change allocated to size of new sequence
	}


	// NON-MEMBER FUNCTIONS for the string class:
	//   string operator +(const string& s1, const string& s2)
	//     Postcondition: The string returned is the catenation of s1 and s2.
	
	string operator +(const string& s1, const string& s2)
	{
		string concat;																// create string to hold the other two strings

		concat += s1;																// add the first string to the new string
		concat += s2;																// add the second string after the first string in the new string

		return concat;																// return the new string
	}


	//   istream& operator >>(istream& ins, string& target)
	//     Postcondition: A string has been read from the istream ins, and the
	//     istream ins is then returned by the function. The reading operation
	//     skips white space (i.e., blanks, newlines, tabs) at the start of ins.
	//     Then the string is read up to the next white space or the end of the
	//     file. The white space character that terminates the string has not
	//     been read.

	istream& operator >>(istream& ins, string& target)
	{
		char special;																// create a char to check for white spaces and only find regular char's

		while (ins && isspace(ins.peek()))											// ignore any char's that are spaces 
			ins.ignore();

		while (ins && !isspace(ins.peek()))											// when the char is not a space concatenate it to the target string
		{
			ins >> special;															

			target += special;
		}

		return ins;																	// return the char position
	}


	//   ostream& operator <<(ostream& outs, const string& source)
	//     Postcondition: The sequence of characters in source has been written
	//     to outs. The return value is the ostream outs.

	ostream& operator <<(ostream& outs, const string& source)
	{
		outs << source.sequence;											

		return outs;																// return the string that was inputed
	}


	//   void getline(istream& ins, string& target, char delimiter)
	//     Postcondition: A string has been read from the istream ins. The reading
	//     operation starts by skipping any white space, then reading all characters
	//     (including white space) until the delimiter is read and discarded (but
	//     not added to the end of the string). The return value is ins.


	void getline(istream& ins, string& target, char delimiter)
	{
		target = "";																// set string target to a blank string
		
		while (ins && (ins.peek() != '\n'))											// until the next char is the end of the string
		{
			ins.get(delimiter);														// copy the next char

			target += delimiter;													// add that char to the string target
		}
	}


	void string::operator =(const string& source)
	{
		char *nseq;																	// create a char to hold the location of new sequence

		if (allocated <= source.allocated)											// do this as long as the old allocated size isn't bigger then the new allocated size
		{
			nseq = new char [source.allocated];										// point to new char array with a size of the old sequence
			delete [] sequence;														// delete the old sequence
			sequence = nseq;														// point the old sequence to the new sequence
			allocated = source.allocated;											// set the allocated size of the new sequence to the same as the old sequence 
		}
		
		strcpy (sequence, source.sequence);											// copy the chars from the old sequence to the new sequence

		current_length = strlen(source.sequence);									// set the current_length of the new sequence to the same as the old sequence
	}


	//  TOTAL ORDER SEMANTICS for the string class:
	//    The six comparison operators (==, !=, >=, <=, >, and <) are implemented
	//    for the string class, forming a total order semantics, using the usual
	//    lexicographic order on strings.

	bool operator ==(const string& s1, const string& s2)
	{
		return (strcmp(s1.sequence, s2.sequence) == 0);								// returns value based on if the sequences are equal
	}

	bool operator !=(const string& s1, const string& s2)
	{
		return (strcmp(s1.sequence, s2.sequence) != 0);								// returns value based on if the sequences are different
	}

	bool operator >=(const string& s1, const string& s2)
	{
		return (!(strcmp(s1.sequence, s2.sequence) < 0));							// returns value based on if the first sequence is greater than or equal to the second sequence
	}

	bool operator <=(const string& s1, const string& s2)
	{
		return (!(strcmp(s1.sequence, s2.sequence) > 0));							// returns value based on if the first sequence is less than or equal to the second sequence
	}

	bool operator > (const string& s1, const string& s2)
	{
		return (strcmp(s1.sequence, s2.sequence) > 0);								// returns value based on if the first sequence is greater than the second sequence
	}

	bool operator < (const string& s1, const string& s2)
	{
		return (strcmp(s1.sequence, s2.sequence) < 0);								// returns value based on if the first sequence is less than the second sequence
	}
}

