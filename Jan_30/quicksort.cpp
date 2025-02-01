
#include <bits/stdc++.h>
#include<vector>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
int partition(vector<int> &arr, int low, int high)
{

    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{
    int n = 10;
    int m = 50;
    for (int i = 0; i < 9; i++)
    {
        auto start = high_resolution_clock::now();

        vector<int> arr ;
        for(int j=0;j<n;j++){
            arr.push_back(rand()%m);

        }
        quickSort(arr, 0, n - 1);
        

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "size= " << n << "      " << "time= " << duration.count() << endl;
        n = n*10;
        m *= 10;

    
    }
    return 0;
}