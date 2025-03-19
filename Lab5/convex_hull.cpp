#include <bits/stdc++.h>
using namespace std;

typedef ipair<int, int> ipair;

set<ipair> hull;

int findSide(ipair p1, ipair p2, ipair p) {
    int val = (p.second - p1.second) * (p2.first - p1.first) -
              (p2.second - p1.second) * (p.first - p1.first);
    return (val > 0) ? 1 : (val < 0) ? -1 : 0;
}

int lineDist(ipair p1, ipair p2, ipair p) {
    return abs((p.second - p1.second) * (p2.first - p1.first) -
               (p2.second - p1.second) * (p.first - p1.first));
}

void quickHull(ipair points[], int n, ipair p1, ipair p2, int side) {
    int index = -1, maxDist = 0;

    for (int i = 0; i < n; i++) {
        int temp = lineDist(p1, p2, points[i]);
        if (findSide(p1, p2, points[i]) == side && temp > maxDist) {
            index = i;
            maxDist = temp;
        }
    }

    if (index == -1) {
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    quickHull(points, n, points[index], p1, -findSide(points[index], p1, p2));
    quickHull(points, n, points[index], p2, -findSide(points[index], p2, p1));
}

void printHull(ipair points[], int n) {
    if (n < 3) {
        cout << "Convex hull not possible\n";
        return;
    }

    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].first < points[min_x].first)
            min_x = i;
        if (points[i].first > points[max_x].first)
            max_x = i;
    }

    quickHull(points, n, points[min_x], points[max_x], 1);
    quickHull(points, n, points[min_x], points[max_x], -1);

    cout << "The points in Convex Hull are:\n";
    for (auto p : hull)
        cout << "(" << p.first << ", " << p.second << ") ";
}

int main() {
    ipair points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    printHull(points, n);
    return 0;
}