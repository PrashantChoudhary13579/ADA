#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>
using namespace std;

int max(vector<vector<int>> &mat, int n, int m, int col)
{
    int maxval = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > maxval)
        {
            maxval = mat[i][col];
            index = i;
        }
    }
    return index;
}
void findPeak(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = max(mat, n, m, mid);
        int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;
        if (mat[row][mid] > left && mat[row][mid] > right)
        {
            cout << row << "  and  " << mid << "is the peak coordinates" << endl;
            return;
        }
        else if (mat[row][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "no peak found" << endl;
}

int main()
{

    int m, n;
    cout << "Enter the row" << endl;
    cin >> m;
    cout << "Enter the column" << endl;
    cin >> n;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    findPeak(a);
    return 0;
}
