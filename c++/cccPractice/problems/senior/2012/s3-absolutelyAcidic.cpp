#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef pair<int, int> pii;

int n;
int cur = -1;
int nums[2000005];
vector<pii> freq;

bool sortBySec(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.second == p2.second)
    {
        return p1.first > p2.first;
    }
    else
    {
        return p1.second > p2.second;
    }
}

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums + n, greater<int>());

    REP(i, 0, n)
    {
        if (nums[i] != cur)
        {
            freq.push_back(make_pair(nums[i], 1));
            cur = nums[i];
        }
        else
        {
            freq.back().second++;
        }
    }
    sort(freq.begin(), freq.end(), sortBySec);
    int numVals = freq.size();
    if (freq[0].second == freq[1].second)
    {
        REP(i, 2, numVals)
        {
            if (freq[i].second != freq[0].second)
            {
                printf("%d", freq[0].first - freq[i - 1].first);
                return 0;
            }
        }
        printf("%d", freq[0].first - freq[numVals - 1].first);
    }
    else
    {
        REP(i, 2, numVals)
        {
            if (freq[i].second != freq[1].second)
            {
                if (freq[0].first > freq[i - 1].first)
                {
                    printf("%d", freq[0].first - freq[i - 1].first);
                }
                else
                {
                    printf("%d", freq[1].first - freq[0].first);
                }
                return 0;
            }
        }
        if (freq[1].first > freq[0].first)
        {
            printf("%d", freq[1].first - freq[0].first);
            return 0;
        }
        else
        {
            printf("%d", freq[0].first - freq[1].first);
            return 0;
        }
    }
}