#include <bits/stdc++.h>
using namespace std;

int sum_of_elements(int arr[], int size){
  if ( size == 0 ){
    return 0;
  }
  return arr[0] + sum_of_elements(arr+1, size-1);
}

int main()
{
  int arr[] = {1, 2, 30, 4, 5};

  int n = sizeof(arr) / sizeof(arr[0]);

  int sum = sum_of_elements(arr, n);
  cout << "Sum of elements is " << sum << endl;

  return 0;
}