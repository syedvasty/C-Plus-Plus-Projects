
// implementation

// #include <cassert>
// #include <algorithm>
#include "sequence1.h"

using namespace std;

namespace main_savitch_3
{
	 typedef double value_type;
     typedef std::size_t size_type;

	 // CONSTRUCTOR for the sequence class:
	 //   sequence( )
	 //     Postcondition: The sequence has been initialized as an empty sequence.
	 
	 sequence::sequence()																		// set up blank sequence
	 {
		 used = 0;
		 current_index = 0;
	 }


	 //   void start( )
	 //   Postcondition: The first item on the sequence becomes the current item
	 //   (but if the sequence is empty, then there is no current item).

	 void sequence::start()																		// return current_index to 1
	 {
		 if (used != 0)
			 current_index = 1;
	 }


	 //   void advance( )
	 //     Precondition: is_item returns true.
	 //     Postcondition: If the current item was already the last item in the
	 //     sequence, then there is no longer any current item. Otherwise, the new
	 //     current item is the item immediately after the original current item.

	 void sequence::advance()
	 {
		 bool check = is_item();																// set variable to value of is_item

		 if (check == true)																		// do if is_item was true
		 {
			 if (current_index == used)
				 current_index = 0;
			 else
				 current_index ++;																// increase current_index by 1
		 }
	 }

	 
	 //   void insert(const value_type& entry)
	 //     Precondition: size( ) < CAPACITY.
	 //     Postcondition: A new copy of entry has been inserted in the sequence
	 //     before the current item. If there was no current item, then the new entry 
	 //     has been inserted at the front of the sequence. In either case, the newly
	 //     inserted item is now the current item of the sequence.

	 void sequence::insert(const value_type& entry)
	 {
		 if (size() < CAPACITY)
		 {
			 bool value = is_item();
			 bool loop = false;
			 value_type old, a;																	// variables to hold sequence data
			 value_type count;																	// variable to store loop amount
			 int place;																			// variable to mark current item

			 count = current_index;																// start count at current item
			 place = current_index;																// start place at current item

			 if (value == false && used != 0)
			 {
				 current_index = 1;
				 loop = true;

				 count = current_index;															// start count at current item
				 place = current_index;															// start place at current item
			 }

			 if (value == true || loop == true)													// if sequence is not empty do this
			 {
				 old = data[current_index - 1];													// copy current item data

				 data[current_index - 1] = entry;												// insert entry into current item data
			 
				 for (count; count<=used; count++)												// loop to shift data down the line after insert
				 {
					a = data[place];
					data[place] = old;
					old = a;

					place++;
				 }
			 }
			 else																				// if sequence is empty do this
			 {
				old = data[current_index];
				data[current_index] = entry;
			 
				current_index = 1;																// set current index to new item if it is the first item in the sequence
			 }
			 
			 used ++;																			// increase used by 1
		 }
	 }

	 
	 //   void attach(const value_type& entry)
	 //     Precondition: size( ) < CAPACITY.
	 //     Postcondition: A new copy of entry has been inserted in the sequence after
	 //     the current item. If there was no current item, then the new entry has 
	 //     been attached to the end of the sequence. In either case, the newly
	 //     inserted item is now the current item of the sequence.

	 void sequence::attach(const value_type& entry)												
	 {
		 if (size() < CAPACITY)																	
		 {
			 bool value = is_item();															
			 value_type current, next;															// variables to hold sequence data
			 value_type count;																	// variable to store loop amount
			 int place;																			// variable to mark current item

			 if (value == false && used != 0)													// do this if current_index isn't on a number
				 current_index = (used);

			 if (value == true)																	// do this if current_index is on a number
			 {
				 count = current_index;
				 place = current_index;

				 current = data[place];
				 data[place] = entry;
				 
				 if (place < 29)																// stops loop if it would cause an extremely long loop
				 {
					 for (count; count<=used; count++)											// loop to shift items down the sequence
					 {
						 next = data[place + 1];
						 data[place + 1] = current;
						 current = next;

						 place ++;
					 }
				 }
				 current_index++;
			 }
			 else																				// do this for new sequences or if the current item isn't a number
			 {																					// this else statement corrects issues from misplaced current_index
				 current = data[current_index];
				 data[current_index] = entry;

				 if (used == 0)
					current_index = 1;
				 else
					current_index++;
			 }

			 used++;
		 }
	 }

	 
	 //   void remove_current( )
	 //     Precondition: is_item returns true.
	 //     Postcondition: The current item has been removed from the sequence, and the
	 //     item after this (if there is one) is now the new current item.

	 void sequence::remove_current()
	 {
		 bool check = is_item();																// set variable to value of is_item

		 if (check == true)																		// do if is_item is true
		 {
			 value_type a;																		// variable to hold sequence data
			 value_type count;																	// variable to store loop amount
			 int place;																			// variable to mark current item
			 
			 count = current_index;																// start count at one past current item
			 place = current_index;																// start place at one past current item

			 for (count; count<used; count++)													// loop to move all data over by 1 slot
			 {
				 a = data[place];

				 data[place - 1] = a;

				 place++;
			 }

			 used --;																			// decrease used by 1
		 }
	 }

	 
	 //   size_type size( ) const
	 //     Postcondition: The return value is the number of items in the sequence.

	 size_type sequence::size() const
	 {
		 return used;																			// returns items in sequence
	 }

	 
	 //   bool is_item( ) const
	 //     Postcondition: A true return value indicates that there is a valid
	 //     "current" item that may be retrieved by activating the current
	 //     member function (listed below). A false return value indicates that
	 //     there is no valid current item.

	 bool sequence::is_item() const
	 {
		 bool current = false;																	// variable to tell if current item is an item

		 if (current_index != 0)																
			 current = true;
		 if (current_index > used)
			 current = false;

		 return current;
	 }

	 
	 //   value_type current( ) const
	 //     Precondition: is_item( ) returns true.
	 //     Postcondition: The item returned is the current item in the sequence.

	 value_type sequence::current() const
	 {
		 bool check = is_item();																// set variable to value of is_item

		 if (check == true)																		// do if is_item is true
		 {
			 value_type item;

			 item = data[current_index - 1];

			 return item;
		 }
	 }	 
}



/*
output using sequence_exam



Running tests for Chapter 3 sequence Class

START OF TEST 1:
Testing insert, attach, and the constant member functions (50 points).
Starting with an empty sequence.
Testing that size() returns 0 ... Passed.
Testing that is_item() returns false ... Passed.
I'll call start() and look at the items one more time...
All tests passed for this sequence.

I am now using attach to put 10 into an empty sequence.
Testing that size() returns 1 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

I am now using insert to put 10 into an empty sequence.
Testing that size() returns 1 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

I am now using attach to put 10,20,30 in an empty sequence.
Then I move the cursor to the start and insert 5.
Testing that size() returns 4 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

I am now using attach to put 10,20,30 in an empty sequence.
Then I move the cursor to the start, advance once, and insert 15.
Testing that size() returns 4 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

I am now using attach to put 10,20,30 in an empty sequence.
Then I move the cursor to the start and attach 15 after the 10.
Testing that size() returns 4 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

All tests of this first function have been passed.
Test 1 got 50 points out of a possible 50.
END OF TEST 1.


START OF TEST 2:
Testing situations where the cursor goes off the sequence (25 points).
Using attach to put 20 and 30 in the sequence, and then calling
advance, so that is_item should return false ... passed.
Inserting 10, which should go at the sequence's front.
Then calling advance three times to run cursor off the sequence ... passed.
Calling attach to put the numbers 40, 50, 60 ...300 at the sequence's end.
Now I will test that the sequence has 10, 20, 30, ...300.
All tests of this second function have been passed.
Test 2 got 25 points out of a possible 25.
END OF TEST 2.


START OF TEST 3:
Testing remove_current (25 points).
Using attach to build a sequence with 10,30.
Insert a 20 before the 30, so entire sequence is 10,20,30.
Testing that size() returns 3 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Remove the 20, so entire sequence is now 10,30.
Testing that size() returns 2 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Remove the 30, so entire sequence is now just 10 with no cursor.
Testing that size() returns 1 ... Passed.
Testing that is_item() returns false ... Passed.
I'll call start() and look at the items one more time...
All tests passed for this sequence.

Set the cursor to the start and remove the 10.
Testing that size() returns 0 ... Passed.
Testing that is_item() returns false ... Passed.
I'll call start() and look at the items one more time...
All tests passed for this sequence.

Using attach to build another sequence with 10,30.
Insert a 20 before the 30, so entire sequence is 10,20,30.
Testing that size() returns 3 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Remove the 20, so entire sequence is now 10,30.
Testing that size() returns 2 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [1] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Set the cursor to the start and remove the 10,
so the sequence should now contain just 30.
Testing that size() returns 1 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Remove the 30 from the sequence, resulting in an empty sequence.
Testing that size() returns 0 ... Passed.
Testing that is_item() returns false ... Passed.
I'll call start() and look at the items one more time...
All tests passed for this sequence.

Build a new sequence by inserting 30, 10, 20 (so the sequence
is 20, then 10, then 30). Then remove the 20.
Testing that size() returns 2 ... Passed.
Testing that is_item() returns true ... Passed.
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
I'll call start() and look at the items one more time...
The cursor should be at item [0] of the sequence
(counting the first item as [0]). I will advance the cursor
to the end of the sequence, checking that each item is correct...Passed.
All tests passed for this sequence.

Just for fun, I'll empty the sequence then fill it up, then
empty it again. During this process, I'll try to determine
whether any of the sequence's member functions access the
array outside of its legal indexes.
All tests of this third function have been passed.
Test 3 got 25 points out of a possible 25.
END OF TEST 3.

If you submit the Chapter 3 sequence to Dora now, you will have
100 points out of the 100 points from this test program.
Press any key to continue . . .

*/