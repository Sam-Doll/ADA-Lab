#include<iostream>
using namespace std;

bool binarySearch(int arr[], int n, int key, int s, int e)
{
    if (s > e) 
        return false; // Base case: element not found

    int mid = s + (e - s) / 2; // Find the middle element

    if (key == arr[mid]) 
        return true; // If key is found at mid

    if (key < arr[mid]) 
        return binarySearch(arr, n, key, s, mid - 1); // Search in the left half

    if (key > arr[mid]) 
        return binarySearch(arr, n, key, mid + 1, e); // Search in the right half
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40}; // Example sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10; // Key to search for

    bool result = binarySearch(arr, n, key, 0, n - 1); // Search for the key in the entire array
    if (result)
        cout << "Element found" << endl; // If element is found
    else
        cout << "Element not found" << endl; // If element is not found

    return 0;
}
