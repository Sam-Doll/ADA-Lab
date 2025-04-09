#include<iostream>
#include<chrono>
#include <vector>
#include <cstdlib> // for rand()
using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int s, int e)
{
    int start = s;
    int end = e;
    int pivot = arr[s];

    while (start <= end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[s], arr[end]);
    return end;
}

void quickSort(vector<int>& arr, int s, int e)
{
    if (s >= e) return;

    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int n = 1000;
    while (n <= 10000)
    {
        long long total_time = 0; // Store time in microseconds

        for (int i = 1; i < 10; i++)
        {
            vector<int> arr(n);  // Create a vector of size n
            for (int j = 0; j < n; j++)
            {
                arr[j] = rand();
            }

            // Measure the start time
            auto start_time = high_resolution_clock::now();

            // Sort the array using quick sort
            quickSort(arr, 0, n - 1);

            // Measure the final time
            auto end_time = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(end_time - start_time).count();

            total_time += duration;
        }
        double avg_time = total_time / 10.0 / 1000.0;  // avg_time is in milliseconds

        // Print - showing n on x-axis and avg_time on y-axis
        cout << "Size of array: " << n << " | Avg Time (ms): " << avg_time << endl;
        n += 1000;
    }
    return 0;
}
