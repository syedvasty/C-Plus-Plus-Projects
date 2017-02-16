#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVector(vector<int>);

int main()
{
	int arr[] = {3, 9, 1, 2, 13, 4, 8, 7};
	vector<int> v(arr, arr+8);

	printVector(v);

	sort(arr, arr+8);

	for(int i=0; i<8; i++)
		cout << arr[i] << endl;

	printVector(v);
	


}

void printVector(vector<int> v)
{
	for (int i=0; i<v.size(); i++)
		cout << "Array[" << i << "] = " << v[i] << endl;
}