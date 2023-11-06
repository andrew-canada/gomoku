#include <stdio.h>
#include <vector>

using namespace std;

int main()
{

    vector<vector<int>> days;
    int start = 0;
    for (int i = start + 1; i < n; i++)
    {
        if (A[i] < A[i - 1] && A[i - 1] > A[i - 2] || i == n - 1)
        {
            days.push_back({start, i - 1});
            start = i;
        }
    }
    return days;
}