#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void solveNQueens(int col, int n, vector<int>& positions, vector<bool>& rows,
                  vector<bool>& diag1, vector<bool>& diag2, vector<vector<int>>& solutions) {
    if (col > n) {
        solutions.push_back(positions);
        return;
    }

    for (int row = 1; row <= n; ++row) {
        if (!rows[row] && !diag1[row + col] && !diag2[row - col + n]) {
            rows[row] = diag1[row + col] = diag2[row - col + n] = true;
            positions.push_back(row);

            solveNQueens(col + 1, n, positions, rows, diag1, diag2, solutions);

            positions.pop_back();
            rows[row] = diag1[row + col] = diag2[row - col + n] = false;
        }
    }
}

vector<vector<int>> findNQueenSolutions(int n) {
    vector<vector<int>> solutions;
    vector<int> positions;
    vector<bool> rows(n + 1, false);
    vector<bool> diag1(2 * n + 1, false);
    vector<bool> diag2(2 * n + 1, false);

    solveNQueens(1, n, positions, rows, diag1, diag2, solutions);
    return solutions;
}

int main() {
    ofstream outFile("queen.csv");
    outFile << "N,ExecutionTime(ms),Solutions\n"; // Header

    for (int n = 4; n <= 13; ++n) { // You can increase upper limit based on your system
        auto start = high_resolution_clock::now();

        vector<vector<int>> solutions = findNQueenSolutions(n);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "N = " << n << " | Time = " << duration.count() << " ms | Solutions = " << solutions.size() << endl;

        outFile << n << "," << duration.count() << "," << solutions.size() << "\n";
    }

    outFile.close();
    cout << "Data written to queen.csv\n";
    return 0;
}
