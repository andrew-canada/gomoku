#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, k;
int sums[1000005];
int dp[1000005][1000005];
int num;

int nCk(int n, int k);

int main()
{
    scanf("%d%d", &n, &k);
    REP(i, 0, n - k + 1)
    {
        scanf("%d", &sums[i]);
    }
    num += nCk(k, sums[0]);

    printf("%d", num);
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