// bag implementation
#include <cassert>
#include <algorithm>																			// for copy

using namespace std;																			// for copy

#include "bag.h"

namespace main_savitch_3
{
	typedef int value_type;
	typedef std::size_t size_type;
	
	//   bag operator +(const bag& b1, const bag& b2)
	//     Precondition:  b1.size( ) + b2.size( ) <= bag::CAPACITY.
	//     Postcondition: The bag returned is the union of b1 and b2.
	bag operator +(const bag& b1, const bag& b2)
	{
		assert(b1.size() + b2.size() <= bag::CAPACITY);

		bag temp;

		temp += b2;
		temp += b1;

		return temp;
	}



	//   void operator +=(const bag& addend)
	//     Precondition:  size( ) + addend.size( ) <= CAPACITY.
	//     Postcondition: Each item in addend has been added to this bag.
	void bag::operator +=(const bag& addend)
	{
		assert(size() + addend.size() <= CAPACITY);

		copy(addend.data, addend.data + addend.used, data + used);								// copy bag into bag
		used += addend.used;
	}
	


	
	//   size_type erase(const value_type& target);
	//     Postcondition: All copies of target have been removed from the bag.
	//     The return value is the number of copies removed (which could be zero).
	size_type bag::erase(const value_type& target)
	{
		size_type count = 0;

		while (erase_one(target))
			++count;

		return count;
	}





	//   void erase_one(const value_type& target)
	//     Postcondition: If target was in the bag, then one copy has been removed;
	//     otherwise the bag is unchanged. A true return value indicates that one
	//     copy was removed; false indicates that nothing was removed.
	bool bag::erase_one(const value_type& target)
	{
		for (size_type i=0; i<used; i++)
		{
			if (data[i] == target)
			{
				// remove with last element
				data[i] = data[used - 1];
				--used;

				return true;
			}
		}
		return false;
	}
	
	
	
	
	
	//   size_type count(const value_type& target) const
	//     Postcondition: The return value is number of times target is in the bag.
	size_type bag::count(const value_type& target) const
	{
		size_type numTimes= 0;

		for (size_type i=0; i<used; i++)
			if (data[i] == target)
				++numTimes;

		return numTimes;
	}
	
	
	
	
	//   void insert(const value_type& entry)
	//     Precondition:  size( ) < CAPACITY.
	//     Postcondition: A new copy of entry has been added to the bag.
	void bag::insert(const value_type& entry)
	{
		assert(size() < CAPACITY);
		
		data[used] = entry;
		++used;
	}



}