#include <bits/stdc++.h>
using namespace std;

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
};

void selection_sort(int a[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      int maxi = i;
      for (int j = i + 1; j < n; j++)
      {
         if (a[j] > a[maxi])
         {
            maxi = j;
         }
      }
      if (maxi != i)
      {
         swap(a[maxi], a[i]);
      }
   }
}

void insertion_sort(int a[], int n)
{
   for (int i = 1; i < n; i++)
   {
      int element = a[i];
      int j = i - 1;
      while (j >= 0 && a[j] < element)
      {
         a[j + 1] = a[j];
         j--;
      }
      a[j + 1] = element;
   }
}

void merge(int a[], int l, int mid, int r) {
    int i = l, j = mid + 1, k = 0;
    int b[r - l + 1];

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while (i <= mid) {
        b[k++] = a[i++];
    }

    while (j <= r) {
        b[k++] = a[j++];
    }

    for (int p = 0; p < k; p++) {
        a[l + p] = b[p];
    }
}

void merge_sort(int a[], int l, int r){
   if ( l < r ){
      int mid = ( l + r )/2;
      merge_sort(a, l, mid);
      merge_sort(a, mid+1, r);
      merge(a, l, mid, r);
   }
}

int main()
{
   int arr[] = {32, 1, 3, -1, 17, 19, 100, 14, 500};
   int n = sizeof(arr) / sizeof(arr[0]);

   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
   // bubble_sort(arr, n);
   // selection_sort(arr, n);
   // insertion_sort(arr, n);
   merge_sort(arr, 0, n);

   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;

   return 0;
}