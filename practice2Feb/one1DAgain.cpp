#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

void one_D_peak(vector<int> vec, int low, int high)
{
    if (vec[0] > vec[1] || vec[high - 1] > vec[high - 2])
        return;

    int mid = (low + high) / 2;
    if (vec[mid] > vec[mid - 1] && vec[mid] > vec[mid + 1])
        return;
    else if (vec[mid] > vec[mid + 1])
        one_D_peak(vec, low, mid - 1);
    else
        one_D_peak(vec, mid + 1, high);
}

int main()
{
    srand(time(0));

    vector<int> sizes;
    vector<long long> times;

    int size = 10, m = 20;
    for (int i = 0; i < 8; i++) // Run for different sizes
    {
        vector<int> v(size);
        for (int j = 0; j < v.size(); j++)
            v[j] = rand() % m;

        auto start = high_resolution_clock::now();
        one_D_peak(v, 0, v.size());
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);

        sizes.push_back(size);
        times.push_back(duration.count());

        cout << "Size = " << size << "  Time = " << duration.count() << " ns" << endl;
        
        size *= 10; // Increase input size
        m *= 10;
    }

    // Save results to a file for Python
    FILE *fp = fopen("complexity.txt", "w");
    for (size_t i = 0; i < sizes.size(); i++)
        fprintf(fp, "%d %lld\n", sizes[i], times[i]);
    fclose(fp);

    return 0;
}
