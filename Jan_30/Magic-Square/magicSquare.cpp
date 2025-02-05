#include <iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;


void magic_square(int **arr, int n)
{
    int row = 0;
    int col = n / 2;
    int i = 1;
    while (i <= n * n)
    {
        arr[row][col] = i;

        int next_row = (row - 1 + n) % n;
        int next_col = (col - 1 + n) % n;

        if (arr[next_row][next_col] != 0)
        {
            row = (row + 1) % n;
        }
        else
        {
            row = next_row;
            col = next_col;
        }
        i++;
    }
}

int main()
{
    int n = 5;

    FILE *fp = fopen("magic_square.csv", "w");
    if (fp == NULL)
    {
        cout << "Could not open file" << endl;
        }

    
    fprintf(fp,"size,Time(ms)\n");
    for (int i = 0; i <= 1000; i++)
    {
        int **arr = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
        }

        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
        auto start = high_resolution_clock::now();
        magic_square(arr, n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        fprintf(fp, "%d,%lld\n", n, duration.count());

        n +=2;
        
    }

    fclose(fp);
    

    cout << "Data successfully written to magic_square.csv" << endl;
    

    // magic_square(arr, n);
}