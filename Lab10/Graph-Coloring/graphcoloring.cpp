#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, int color, vector<vector<int>>& graph, vector<int>& colors, int n) {
    for (int i = 0; i < n; ++i) {
        if (graph[node][i] && colors[i] == color)
            return false;
    }
    return true;
}

void solve(int node, int n, int m, vector<vector<int>>& graph, vector<int>& colors, vector<vector<int>>& solutions) {
    if (node == n) {
        solutions.push_back(colors);
        return;
    }

    for (int c = 1; c <= m; ++c) {
        if (isSafe(node, c, graph, colors, n)) {
            colors[node] = c;
            solve(node + 1, n, m, graph, colors, solutions);
            colors[node] = 0; // backtrack
        }
    }
}

void graphColoring(vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> colors(n, 0);
    vector<vector<int>> solutions;

    solve(0, n, m, graph, colors, solutions);

    if (solutions.empty()) {
        cout << "No possible coloring found.\n";
    } else {
        cout << "All possible colorings:\n";
        for (auto& sol : solutions) {
            for (int color : sol) {
                cout << color << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    // Adjacency matrix
    // 4 nodes, edges between: 0-1, 0-2, 1-2, 1-3
    vector<vector<int>> graph = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}
    };
    // Number of colors
    int m = 3; 

    graphColoring(graph, m);

    return 0;
}
