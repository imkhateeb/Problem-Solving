#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp(high - low + 1);

    int i = low;
    int j = mid + 1;
    int st = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[st] = arr[i];
            i++;
        }
        else
        {
            temp[st] = arr[j];
            j++;
        }
        st++;
    }

    for(; j <= high; j++){
        temp[st] = arr[j];
        st++;
    }

    for(; i <= mid; i++){
        temp[st] = arr[i];
        st++;
    }

    int n = high-low+1;

    for(int i = 0; i < n; i++){
        arr[low] = temp[i];
        low++;
    }
}

void mergeSort(int low, int high, vector<int> &arr)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;

    mergeSort(low, mid, arr);
    mergeSort(mid + 1, high, arr);
    merge(arr, low, mid, high);
}

int main()
{

    vector<int> arr = {9, 2, 23, 43, 2, -4, 1, 0, 100};

    mergeSort(0, 8, arr);

    for(auto it: arr) cout << it << " ";

    cout << endl;

    return 0;
}