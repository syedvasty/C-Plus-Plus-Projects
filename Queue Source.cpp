#include <iostream>
#include <queue>

using namespace std;

void radixSort(vector<int>&);
void printVector(vector<int>);

int main()
{
/*
	//	queue<int> q;
	priority_queue<int> q;

	q.push(29);
	q.push(17);
	q.push(34);

	cout << "Size = " << q.size() << endl;

	while (!q.empty())
	{
//		cout << q.front() << " ";
		cout << q.top() << " ";
		q.pop();
	}

	cout << endl;
*/

	int arr[] = {91, 6, 85, 15, 92, 35, 30, 22, 39};
	vector<int> v(arr, arr + 9);

	cout << "Initial Array" << endl;
	printVector(v);

	radixSort(v);



	return EXIT_SUCCESS;
}

void printVector(vector<int> v)
{
	for (int i=0; i<v.size(); i++)
		cout << v[i] << " ";

	cout << endl;
}

void radixSort(vector<int>& v)
{
	int i, place;
	queue<int> q[10];

	for (i=0; i<2; i++)
	{
		place = int(pow(10, i));
		
		// 1. distribute
		for (int j=0; j<v.size(); j++)
			q[(v[j] / place) % 10].push(v[j]);
		
		// 2. collect
		for (int j=0, count=0; j<10; j++)
		{
			while (!q[j].empty())
			{
				v[count] = q[j].front();

				count++;
				q[j].pop();
			}
		}

		cout << "After Pass #" << i+1 << endl;
		printVector(v);
	}
}