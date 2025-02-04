#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
using namespace std;

void print(vector<vector<int>> vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int m = 100;
    vector<vector<int>> vec(size, vector<int>(size));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            vec[i][j] = rand() % m;
        }
    }

    print(vec, size);

    FILE *fp = fopen("twoDpeakdata.txt", "a");
    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec.size(); j++)
        {
            fprintf(fp, "%d ", vec[i][j]);
        }
        // fprint("\n");
    }
    fclose(fp);
    return 0;
}
