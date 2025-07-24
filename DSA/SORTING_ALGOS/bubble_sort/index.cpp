#include <iostream>
using namespace std;
#include "bubble_sort.h"

int main()
{
   int arr[] = {32, 1, 3, -1, 17, 19};
   int n = sizeof(arr) / sizeof(arr[0]);

   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
   bubble_sort(arr, n);

   for ( int i = 0; i < n; i++ ){
      cout << arr[i] << " ";
   } cout << endl;

   return 0;
}