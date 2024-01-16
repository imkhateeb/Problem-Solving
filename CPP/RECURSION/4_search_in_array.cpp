#include <bits/stdc++.h>
using namespace std;

int is_sorted(int arr[], int size)
{
  if (size == 1)
    return 1;
  if (arr[0] > arr[1])
    return 0;
  return is_sorted(arr + 1, size - 1);
}

int binary_search(int arr[], int start, int end, int key)
{
  if (start > end)
  {
    return -1;
  }

  int mid = start + (end - start) / 2;

  if (arr[mid] == key)
  {
    return mid;
  }
  else if (arr[mid] > key)
  {
    return binary_search(arr, start, mid - 1, key);
  }
  else
  {
    return binary_search(arr, mid + 1, end, key);
  }
}

int linear_search(int arr[], int size, int key)
{
  if (size == 0)
  {
    return -1;
  }
  if (arr[0] == key)
  {
    return 0;
  }
  return linear_search(arr + 1, size - 1, key);
}

int main()
{
  int arr[] = {1, 21, 32, 35, 67, 89, 90};

  int n = sizeof(arr) / sizeof(arr[0]);

  int ans = is_sorted(arr, n);

  int key = 90;
  if (ans)
  {
    int is_key = binary_search(arr, 0, n - 1, key);
    if (is_key == -1)
    {
      cout << "Key not found" << endl;
    }
    else
    {
      cout << "Key found" << endl;
    }
  }
  else
  {
    cout << "Array is not sorted" << endl;
    int is_key = linear_search(arr, n, key);
    if (is_key == -1)
    {
      cout << "Key not found" << endl;
    }
    else
    {
      cout << "Key found" << endl;
    }
  }

  return 0;
}