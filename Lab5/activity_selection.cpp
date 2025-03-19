#include <bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> &start, vector<int> &end) {
    int ans = 0;
    vector<pair<int,int>> arr;

    for (int i = 0; i < start.size(); i++) {
        arr.push_back(make_pair(end[i], start[i]));
    }

    sort(arr.begin(), arr.end());

    int finish = -1;

    for(int i = 0; i < arr.size(); i++) {
        pair<int,int> activity = arr[i];
        if (activity.second > finish) {
            finish = activity.first;
            ans++;
        }
    }
    return ans;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << activitySelection(start, end); 
    return 0;
}
