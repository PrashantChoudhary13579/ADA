#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

bool isSafe(int node, int color, const vector<vector<int>>& graph, const vector<int>& colors, int n) {
    for (int i = 0; i < n; ++i) {
        if (graph[node][i] && colors[i] == color)
            return false;
    }
    return true;
}

void solve(int node, int n, int m, const vector<vector<int>>& graph, vector<int>& colors, bool& found) {
    if (node == n) {
        found = true;
        return;
    }

    for (int c = 1; c <= m; ++c) {
        if (isSafe(node, c, graph, colors, n)) {
            colors[node] = c;
            solve(node + 1, n, m, graph, colors, found);
            if (found) return;  // stop after first valid coloring
            colors[node] = 0;
        }
    }
}

void graphColoring(const vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> colors(n, 0);
    bool found = false;

    solve(0, n, m, graph, colors, found);
}

vector<vector<int>> generateRandomGraph(int n) {
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int edge = rand() % 2;
            graph[i][j] = graph[j][i] = edge;
        }
    }
    return graph;
}

int main() {
    srand(time(0));
    ofstream fout("complexity.csv");
    fout << "nodes,time_seconds\n";

    // Run for increasing values of n (adjust upper limit carefully due to exponential time)
    for (int n = 10; n <= 100; n += 10) {
        vector<vector<int>> graph = generateRandomGraph(n);
        int m = 3; // Number of colors

        auto start = high_resolution_clock::now();
        graphColoring(graph, m);
        auto end = high_resolution_clock::now();

        double duration = duration_cast<microseconds>(end - start).count() / 1e6;
        fout << n << "," << duration << "\n";
        cout << "Nodes: " << n << " -> Time: " << duration << "s\n";
    }

    fout.close();
    return 0;
}
