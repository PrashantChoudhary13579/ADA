#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
}
void buildminHeap(int b[], int n)
{
    // int n = b.size();
    int t = n;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    // int n = 5;

    for (int i = t / 2 - 1; i >= 0; i--)
    {
        heapify(b, i, t);
    }

    cout << endl;
    cout << "Heap after heapify " << endl;
    print(b, n);
    
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
void print2d(int arr[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void Kruskal(int arr[][3], int n, int out[][2])
{

    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = arr[i][2];
    }

    buildminHeap(b, n);

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

    while (i < n - 1 && j >= 0)
    {
        swap(b[j], b[0]);
        cout << endl;

        int val = b[j];
        for (int s = 0; s < n; s++)
        {
            if (val == arr[s][2])
            {
                // cout<<arr[s][2]<<" ";
                u = arr[s][0];
                v = arr[s][1];

                cout << "Edge " << u << "," << v << endl;
            }
        }
        heapify(b, 0, j);
        j = j - 1;

        int a = find(p, n, u);
        int b = find(p, n, v);
        cout << "Parents ";
        cout << a << "," << b << endl;
        if (a != b)
        {
            i++;
            mincost = mincost + val;
            out[i][0] = u;
            out[i][1] = v;
            unions(a, b, p);
        }
    }
    cout<< i<<endl;
    if( i != n-1 ){
        cout<<"Spanning tree does not exist "<<endl;
    }
        cout << "Edges which comes in making MST " << endl;
        print2d(out, n);

        cout << "Weight of MST " << mincost << endl;
}
int main()
{
    int n=12;
    int arr[n][3] = {
    {0, 1, 50},   
    {0, 2, 30},   
    {1, 3, 70},   
    {1, 4, 40},   
    {2, 5, 90},   
    {3, 6, 20},   
    {4, 7, 80},   
    {5, 8, 60},   
    {6, 9, 100},  
    {7, 10, 10},  
    {8, 11, 110},  
    {2, 6, 120}  
    };
    
    int out[n][2] = {-1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            out[i][j] = -1;
        }
    }
    cout << "Initial output edges " << endl;
    print2d(out, n);
    Kruskal(arr, n, out);
    return 0;
}