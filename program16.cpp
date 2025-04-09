#include<bits/stdc++.h>
using namespace std;

struct Item {
    int profit; // profit value
    int weight; // weight value
};

// Comparing two items based on their profit-to-weight ratio
bool compare(Item a, Item b) {
    double p1 = (double)a.profit / a.weight;
    double p2 = (double)b.profit / b.weight;

    return p1 > p2; // sort items in descending order of profit/weight ratio
}

double fractionalKnapsack(int m, int n, int p[], int w[]) {
    vector<Item> items(n); // Vector to store profit and weight of each item
    for (int i = 0; i < n; i++) {
        items[i] = {p[i], w[i]}; // Populating vector with profit and weight of items
    }

    // Sorting items based on the profit-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0; // Total profit we can get
    int remainingCapacity = m; // Remaining capacity of knapsack

    for (auto& item : items) {
        if (remainingCapacity >= item.weight) { // If the item can be taken completely
            remainingCapacity -= item.weight;
            totalProfit += item.profit;
        } else { // Take a fraction of the item
            totalProfit += item.profit * ((double)remainingCapacity / item.weight);
            break; // Knapsack is full
        }
    }
    return totalProfit; // Return the maximum profit
}

int main() {
    int n, m;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> m;

    int p[n], w[n];
    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> w[i]; // Input profit and weight for each item
    }

    double maxProfit = fractionalKnapsack(m, n, p, w); // Get the maximum profit
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
