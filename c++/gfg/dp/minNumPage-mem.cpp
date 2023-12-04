#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int mp(int *arr, int n, int s);

int psa[100];
int dp[100][100];

int main()
{
    int n = 4;
    int arr[4] = {1, 2, 3, 4};
    psa[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        psa[i] = psa[i - 1] + arr[i];
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", mp(arr, n, 2));
}

int mp(int *arr, int n, int s)
{
    if (n == 1)
    {
        return arr[0];
    }
    if (s == 1)
    {
        return psa[n - 1];
    }
    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }
    dp[n][s] = INF;
    for (int i = 1; i < n; i++)
    {
        dp[n][s] = min(dp[n][s], max(psa[n - 1] - psa[i - 1], mp(arr, i, s - 1)));
    }
    return dp[n][s];
}