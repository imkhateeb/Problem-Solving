#include <bits/stdc++.h>
using namespace std;

void insert(int elem, vector<int> &arr)
{
	if (arr.size() == 0 || arr[arr.size() - 1] <= elem)
	{
		arr.push_back(elem);
		return;
	}
	int val = arr[arr.size() - 1];
	arr.pop_back();
	insert(elem, arr);
	arr.push_back(val);
}

void sortAnArray(vector<int> &arr)
{
	if (arr.size() == 0)
	{
		return;
	}
	int val = arr[arr.size() - 1];
	arr.pop_back();
	sortAnArray(arr);
	insert(val, arr);
}

int main()
{
	vector<int> arr = {7, 2, 3, 11, 6, 4};
	sortAnArray(arr);
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}