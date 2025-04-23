#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <vector>
using namespace std;
using namespace std::chrono;

struct Item {
    int index, profit, weight;
    double profitPerWeight;
};

// Sort by profit/weight ratio (Greedy strategy)
bool compareByProfitPerWeight(Item a, Item b) {
    return a.profitPerWeight > b.profitPerWeight;
}

// Fractional Knapsack algorithm
double knapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareByProfitPerWeight);
    double totalProfit = 0.0;
    for (auto& item : items) {
        if (item.weight <= capacity) {
            totalProfit += item.profit;
            capacity -= item.weight;
        } else {
            totalProfit += item.profitPerWeight * capacity;
            break;
        }
    }
    return totalProfit;
}

int main() {
    ofstream outFile("time_analysis.csv");
    outFile << "NumItems,ExecutionTimeMicroseconds\n";

    int capacity = 1000;
    for (int n = 10; n <= 1000000; n += 100) {
        vector<Item> items(n);
        for (int i = 0; i < n; i++) {
            items[i].index = i + 1;
            items[i].profit = rand() % 100 + 1;
            items[i].weight = rand() % 100 + 1;
            items[i].profitPerWeight = (double)items[i].profit / items[i].weight;
        }

        auto start = high_resolution_clock::now();
        knapsack(items, capacity);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        outFile << n << "," << duration.count() << "\n";
    }

    outFile.close();
    cout << "Execution time data written to time_analysis.csv" << endl;
    return 0;
}
