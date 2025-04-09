#include <bits/stdc++.h>
using namespace std;

void jaccard(vector<int> arr1, vector<int> arr2)
{
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> set2(arr2.begin(), arr2.end());

    // Calculate the intersection size
    int intersect = 0;
    for (const auto& elem : set1)
    {
        if (set2.find(elem) != set2.end()) {
            intersect++;
        }
    }

    // Calculate the union size
    int uni = set1.size() + set2.size() - intersect;

    // Output the Jaccard coefficient
    cout << "Jaccard coefficient of similarity = " << (double)intersect / uni << endl;
}

int main()
{
    vector<int> arr1 = {0, 1, 2, 5, 6};
    vector<int> arr2 = {0, 2, 3, 4, 5, 7, 9};
    jaccard(arr1, arr2);
    return 0;
}
