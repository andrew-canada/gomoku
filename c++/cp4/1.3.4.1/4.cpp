#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) v.resize(unique(ALL(v)) - v.begin())

int main()
{
    vector<int> nums = {7, 4, 23, 78, 23, 76, 5, -8, 0, 7, 7};
    sort(ALL(nums));
    UNIQUE(nums);
    for (auto &v : nums)
    {
        printf("%d ", v);
    }
}