#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int sums[1000005];
int dp[3005][3005];
int diff;
int num1;
int num0;
const int MOD = 1e6 + 3;
int states[3005];

int nCk(int n, int k);

int main()
{
    freopen("p1.in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    REP(i, 0, n - k + 1)
    {
        scanf("%d", &sums[i]);
    }
    REP(i, 0, k - 1)
    {
        diff = sums[i + 1] - sums[i];
        if (diff < 0)
        {
            num1++;
        }
        else if (diff > 0)
        {
            num0++;
        }
    }
    printf("%d", nCk(k - num1 - num0, sums[0] - num1));
}

int nCk(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    if (dp[n][k])
    {
        return dp[n][k];
    }
    return dp[n][k] = (nCk(n - 1, k - 1) + nCk(n - 1, k)) % MOD;
}