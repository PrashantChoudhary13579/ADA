#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
void insertion_sort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

int main()
{

    int n = 10;
    int m = 50;

    FILE *fp = fopen("insertionData.csv", "w");
    if (fp == NULL)
    {
        printf("Could not open file %s\n", "insertionData.csv");
    }
    fprintf(fp, "Size,Time(ns)\n");
    
    for (int i = 0; i < 1000; i++)
    {
        int val = 100000;
        int *a = new int[n];
        for (int j = 0; j < n; j++)
        {
            a[j] = val;
            val -= 10;
        }

        auto start = high_resolution_clock::now();
        insertion_sort(a, n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        fprintf(fp, "%d,%lld\n", n, duration.count());
        n += 100;
        m += 100;
    }
    fclose(fp);

    cout << "Data successfully uploaded" << endl;

    return 0;
}