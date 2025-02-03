#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <math.h>
#include <unordered_set>
using namespace std;

void one_D_peak(vector<int> vec, int low, int high)
{
    if (vec[0] > vec[1])
    {
        cout << vec[0] << " is the peak element" << endl;
    }
    else if (vec[high - 1] > vec[high - 2])
    {
        cout << vec[high - 1] << " is the peak element" << endl;
    }
    else
    {
        int mid = (low + high) / 2;
        if (vec[mid] > vec[mid - 1] && vec[mid] > vec[mid + 1])
        {
            cout << vec[mid] << " is the peak element" << endl;
        }
        else if (vec[mid] > vec[mid + 1])
        {
            one_D_peak(vec, low, mid - 1);
        }
        else
        {
            one_D_peak(vec, mid + 1, high);
        }
    }
}

int main()
{

    srand(time(0));

    int size = 10;
    int m = 20;
    for (int i = 0; i < 10; i++)
    {

        vector<int> v(size);

        for (int i = 0; i < v.size(); i++)
        {
            v[i] = rand() % m;
        }

        cout << endl;
        int low = 0;
        int high = v.size();
        one_D_peak(v, low, high);


        size *= 10;
        m *= 10;
    }
}