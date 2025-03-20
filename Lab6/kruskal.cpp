#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// void swap()

void heapify(int b[], int i, int n)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && b[left] < b[largest])
    {
        largest = left;
    }
    if (right < n && b[right] < b[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(b[largest], b[i]);
        heapify(b, largest, n);
    }
}
void print(int b[], int n)
{
    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << " ";
    }
}
void buildminHeap(int b[])
{

    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << " ";
    }
    int n = 5;

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(b, i, n);
    }

    cout << endl;
    cout<<"Heap after heapify "<<endl;
    print(b, 5);
    // return b;
}

int find(int p[], int n, int u)
{
    while (p[u] > 0)
    {
        u = p[u];
    }
    return u;
}

void unions(int u, int v, int p[])
{
    p[u] = v;
}

void Kruskal(int arr[5][3], int n, int out[5][2])
{

    int b[5];
    for (int i = 0; i < 5; i++)
    {
        b[i] = arr[i][2];
    }

    // int cost[n];
    buildminHeap(b);

    int p[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = -1;
    }
    cout << endl;

    print(b, n);
    int mincost = 0;
    int j = n - 1;
    int u = -1;
    int v = -1;
    int i = 0;

    while (i <= n - 1 && j >= 0)
    {
        // cout<<b[j]<<" "<<b[0];
        // print(b, n);

        swap(b[j], b[0]);
        cout << endl;
        // cout<<b[j]<<" "<<b[0];
        // cout << b[j] << endl;
        int val = b[j];
        for (int s = 0; s < n; s++)
        {
            if (val == arr[s][2])
            {
                // cout<<arr[s][2]<<" ";
                u = arr[s][0];
                v = arr[s][1];

                cout<<"Edge " << u << "," << v << endl;
            }
        }
        // cout<<b[j]<<endl;
        heapify(b, 0, j);
        j = j - 1;

        int a = find(p, n, u);
        int b = find(p, n, v);
        cout<<"Parents ";
        cout<<a<<","<<b<<endl;
        if (a != b)
        {
            i++;
            mincost = mincost + val;
            out[i][0] = u;
            out[i][1] = v;
            unions(a, b,p);
        }
        // i++;
    }
    cout<<"Weight of MST "<<mincost<<endl;
}
void print2d(int arr[5][2])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[5][3] = {{0, 1, 10}, {1, 3, 15}, {0, 3, 5}, {2, 0, 6}, {2, 3, 4}};

    int n = 5;
    int out[5][2] = {-1};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            out[i][j] = -1;
        }
    }
    cout<<"Initial output edges "<<endl;
    print2d(out);
    Kruskal(arr, n, out);
    cout<<"Edges which comes in making MST "<<endl;
    print2d(out);
}