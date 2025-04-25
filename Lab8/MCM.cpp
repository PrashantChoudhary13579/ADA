#include <bits/stdc++.h>
using namespace std;

int findMinCost(vector<int> &dim, int start, int end) {
    if (start + 1 == end)
        return 0;

    int minCost = INT_MAX;

    for (int k = start + 1; k < end; k++) {
        int cost = findMinCost(dim, start, k) +
                   findMinCost(dim, k, end) +
                   dim[start] * dim[k] * dim[end];

        minCost = min(minCost, cost);
    }

    return minCost;
}

int matrixChainOrder(vector<int> &dim) {
    int n = dim.size();
    return findMinCost(dim, 0, n - 1);
}

int main() {
    vector<int> dim = {2, 1, 3, 4};
    cout << matrixChainOrder(dim);
    return 0;
}
