#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

namespace lab
{
	template<typename T>
	class vpriority_queue
	{
	public:
		// Constructor
		vpriority_queue();
			// default constructor. create an empty priority queue

		void push(const T& item);
			// insert item into the priority queue.
			// Postcondition: the priority queue has one more element

		void pop();
			// remove the highest priority (maximum) item from the priority queue.
			// Precondition: the priority queue is not empty. if it is empty,
			// the function throws the underflowError exception

		T& top(); 
			// return the highest priority (maximum) item in the priority queue
			// Precondition: the priority queue is not empty. if it is empty,
			// the function throws the underflowError exception

		const T& top() const;
			// constant version

		bool empty() const;
			// is the priority queue empty?

		int size() const { return pqVector.size(); }
			// return the size of the priority queue

	private:
		vector<T> pqVector;
			// vector that implements the priority queue

		int findMaxIndex() const;
			// find the index of the maximum value in pqVector

		int maxIndex;
			// index of the maximum value

		bool recomputeMaxIndex;
			// do we need to compute the index of the maximum element?
	};

	template<typename T>
	vpriority_queue<T>::vpriority_queue()						// constructor to create a priority queue
	{
		vector<T> pqVector;										// create vector to hold data
		maxIndex = 0;											// maxIndex is 0
		recomputeMaxIndex = true;								// set variable to say the queue needs to still determine the maxIndex
	}
	
	template<typename T>
	void vpriority_queue<T>::pop()								// function to remove highest priority item in queue
	{
		if (pqVector.empty() == true)							// if queue is empty throw error
			throw "Vector is empty";
		else													// else perform function task
		{
			if (recomputeMaxIndex == true)						// if queue doesn't have maxIndex determined then find it
				maxIndex = findMaxIndex();

			pqVector[maxIndex] = pqVector.back();				// copy last item to maxIndex spot

			pqVector.pop_back();								// remove last item

			recomputeMaxIndex = true;							// set variable to say the queue needs to still determine the maxIndex
		}
	}

	template<typename T>
	T& vpriority_queue<T>::top()								// function to return highest priority item in queue
	{
		if (pqVector.empty() == true)							// if queue is empty throw error
			throw "Vector is empty";
		else													// else perform function task
		{
			if (recomputeMaxIndex == true)						// if queue doesn't have maxIndex determined then find it
				maxIndex = findMaxIndex();

			recomputeMaxIndex = false;							// set variable to say the queue has determined the maxIndex
		}

		return pqVector[maxIndex];								// return the value of the highest item in the queue
	}

	template<typename T>
	bool vpriority_queue<T>::empty() const						// function to detemine if the queue is empty
	{
		const bool empty = true;								// variable to say the queue is empty
		const bool nEmpty = false;								// variable to say the queue is not empty

		if (pqVector.size() > 0)								// if there are items in the queue then return not empty
			return nEmpty;
		else													// else return the queue is empty
			return empty;
	}

	template<typename T>
	void vpriority_queue<T>::push(const T& item)				// function to add item to back of queue
	{
		pqVector.push_back(item);								// add item to the back of the queue
		recomputeMaxIndex = true;								// set variable to say the queue needs to still determine the maxIndex
	}

	template<typename T>
	int vpriority_queue<T>::findMaxIndex() const				// function to find the index of the maximum item in the queue
	{
		int index = 0;											// variable to hold index value
		T temp = pqVector[0];									// variable to hold value of highest item

		for (size_t i=0; i<pqVector.size(); i++)				// loop to find the highest item in the queue and mark its index
			{
				if (pqVector[i] > temp)							// if the current item is greater then the temp, mark it as the new highest item
				{
					temp = pqVector[i];
					index = i;
				}
			}

		return index;											// return the index of the highest item in the queue
	}
}