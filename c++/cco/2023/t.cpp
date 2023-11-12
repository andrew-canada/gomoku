#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, k;
int sums[1000005];
int dp[1000005][1000005];
int num;

int nCk(int n, int k);

int main()
{
    printf("%d\n", nCk(3, 2));
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
    return dp[n][k] = nCk(n - 1, k - 1) + nCk(n - 1, k);
}