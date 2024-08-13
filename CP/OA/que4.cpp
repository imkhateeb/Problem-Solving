#include <iostream>
#include <vector>

using namespace std;

vector<int> rotateArray(vector<int> &arr, int rotations)
{
  int n = arr.size();
  vector<int> result(n);

  rotations = rotations % n;

  for (int i = 0; i < n; ++i)
  {
    result[(i + rotations) % n] = arr[i];
  }

  return result;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  int rotations;
  cout << "Enter the number of rotations: ";
  cin >> rotations;

  vector<int> rotatedArray = rotateArray(arr, rotations);

  for (int i = 0; i < rotatedArray.size(); ++i)
  {
    cout << rotatedArray[i] << " ";
  }
  cout << endl;

  return 0;
}
