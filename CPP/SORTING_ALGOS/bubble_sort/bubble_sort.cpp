#include "bubble_sort.h"

void bubble_sort(int a[], int n)
{
   for (int i = 0; i < n; i++)
   {
      int swapped = 0;
      for (int j = 0; j < n - i - 1; j++)
      {
         if (a[j] > a[j + 1])
         {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            swapped = 1;
         }
      }
      if (!swapped)
         break;
   }
}