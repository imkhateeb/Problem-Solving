#include <bits/stdc++.h>
using namespace std;
int main()
{
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  cout << "Address of first block of array is: " << arr << endl;
  cout << "Address of first block of array is: " << &arr[0] << endl;

  for ( int i = 0; i < 10; i++ ){
    cout << *(arr + i) << " " << *arr + 1 << endl;
  }

  return 0;
}