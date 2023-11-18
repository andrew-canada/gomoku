#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef long long ll;

int n, m;
int nums[100005];
ll psa1[100005], psa2[100005];
int t, l, r;

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &nums[i]);
    }
    psa1[0] = nums[0];
    REP(i, 1, n)
    {
        psa1[i] = psa1[i - 1] + nums[i];
    }
    sort(nums, nums + n);

    psa2[0] = nums[0];
    REP(i, 1, n)
    {
        psa2[i] = psa2[i - 1] + nums[i];
    }

    scanf("%d", &m);
    REP(i, 0, m)
    {
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1)
        {
            printf("%lld\n", psa1[r - 1] - psa1[l - 2]);
        }
        else
        {
            printf("%lld\n", psa2[r - 1] - psa2[l - 2]);
        }
    }
}