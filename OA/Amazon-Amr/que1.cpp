#include <iostream>
using namespace std;

int getMinMoves(int arr[], int n)
{
  int xorred = 0;
  for (int i = 0; i < n; i++)
  {
    xorred ^= arr[i];
  }
  bool allZero = true;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] != 0)
    {
      allZero = false;
      break;
    }
  }

  if (allZero)
  {
    return 0;
  }

  if (xorred == 0)
  {
    return 1;
  }
  else
  {
    return 2;
  }
}

int main()
{

  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << getMinMoves(arr, n) << endl;
}