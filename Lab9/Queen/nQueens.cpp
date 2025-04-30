#include <iostream>
#include <vector>

using namespace std;

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
    int n ;
    cout<<"Enter the value of n "<<endl;
    cin>>n;
    vector<vector<int>> solutions = findNQueenSolutions(n);

    for (const auto& solution : solutions) {
        cout << "[";
        for (int i = 0; i < n; ++i) {
            cout << solution[i];
            if (i != n - 1)
                cout << " ";
        }
        cout << "]\n";
    }

    return 0;
}
