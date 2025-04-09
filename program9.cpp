#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int main() {
    int n = 1000;
    while (n <= 10000) {
        long long total_time = 0; // Store time in microseconds

        for (int i = 1; i < 10; i++) {
            // Step 1 - Generate a random array of size n
            vector<int> arr(n);
            for (int j = 0; j < n; j++) {
                arr[j] = rand();
            }

            // Measure the start time
            auto start_time = high_resolution_clock::now();

            // Step 2 - Sort the array using selection sort
            for (int i = 0; i < n - 1; i++) {
                int mini = i;
                for (int j = i + 1; j < n; j++) {
                    if (arr[j] < arr[mini]) {
                        mini = j;
                    }
                }
                swap(arr[i], arr[mini]);
            }

            // Measure the final time
            auto end_time = high_resolution_clock::now();

            // Calculate the duration in microseconds
            auto duration = duration_cast<microseconds>(end_time - start_time).count();

            total_time += duration;
        }

        // Calculate the average time in milliseconds
        double avg_time = total_time / 10.0 / 1000.0;

        // Print - showing n on x-axis and avg_time on y-axis
        cout << "Size of array: " << n << " | Avg Time (ms): " << avg_time << endl;
        n += 1000;
    }

    return 0;
}
