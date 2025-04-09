#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int s, int mid, int e)
{
    int len1 = mid - s + 1;
    int len2 = e - mid;
    vector<int> left(len1);
    vector<int> right(len2);

    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[s + i];
    }

    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = s;

    while (i < len1 && j < len2)
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while (i < len1)
    {
        arr[k++] = left[i++];
    }
    while (j < len2)
    {
        arr[k++] = right[j++];
    }
}

void mergeSort(vector<int>& arr, int s, int e)
{
    if (s >= e) return;

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

void print(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {24, 55, 12, 9, 100, 40, 32};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}
