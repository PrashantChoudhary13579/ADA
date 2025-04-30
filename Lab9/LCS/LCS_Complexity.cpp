#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

int lcsLength(const string& str1, const string& str2) {
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

string generateRandomString(int length) {
    string result;
    string charset = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < length; ++i) {
        result += charset[rand() % charset.size()];
    }
    return result;
}

int main() {
    ofstream fout("string.csv");
    fout << "length,time_in_seconds\n";

    srand(time(0));  // Seed for random generator

    for (int length = 10; length <= 500; length += 50) {
        string str1 = generateRandomString(length);
        string str2 = generateRandomString(length);

        auto start = high_resolution_clock::now();
        lcsLength(str1, str2);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        double timeInSeconds = duration.count() / 1e6;

        fout << length << "," << timeInSeconds << "\n";
        cout << "Length: " << length << " -> Time: " << timeInSeconds << "s\n";
    }

    fout.close();
    return 0;
}
