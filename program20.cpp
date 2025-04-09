#include<iostream>
using namespace std;

pair<int, int> maxMin(int arr[], int n, int s, int e)
{
    // base case: if the array contains only one element
    if (s == e) return {arr[s], arr[s]}; // return the element as both max and min

    int mid = s + (e - s) / 2; // find the middle index

    // Recursively find max and min in the left and right subarrays
    pair<int, int> leftMaxMin = maxMin(arr, n, s, mid); 
    pair<int, int> rightMaxMin = maxMin(arr, n, mid + 1, e);

    // Calculate the maximum and minimum of both subarrays
    int maxi = max(leftMaxMin.first, rightMaxMin.first); 
    int mini = min(leftMaxMin.second, rightMaxMin.second);

    return {maxi, mini}; // return the maximum and minimum as a pair
}

int main()
{
    int arr[] = {12, 7, 19, 5, 18, 3, 8, 11, 22, 10};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    
    // Find the max and min elements
    pair<int, int> pmaxmin = maxMin(arr, n, 0, n - 1); 

    // Output the results
    cout << "Maximum element: " << pmaxmin.first << endl;
    cout << "Minimum element: " << pmaxmin.second << endl;

    return 0;
}
