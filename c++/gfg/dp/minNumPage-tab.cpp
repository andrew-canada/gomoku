#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int mp(int *arr, int s, int n);

int psa[100];
int dp[100][100];

int main()
{
    int s = 2, n = 4;
    int arr[4] = {1, 2, 3, 4};
    for (int i = 1; i <= n; i++)
    {
        psa[i] = psa[i - 1] + arr[i - 1];
    }
    memset(dp, INF, sizeof(dp));
    printf("%d\n", mp(arr, s, n));
}

int mp(int *arr, int s, int n)
{
    for (int j = 1; j <= n; j++)
    {
        dp[1][j] = psa[j];
    }
    for (int i = 1; i <= s; i++)
    {
        dp[i][1] = psa[1];
    }
    for (int i = 2; i <= s; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            for (int p = 1; p < j; p++)
            {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][p], psa[j] - psa[p]));
            }
        }
    }
    return dp[s][n];
}