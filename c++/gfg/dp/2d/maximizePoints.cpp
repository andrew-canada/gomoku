#include <bits/stdc++.h>

using namespace std;

int dp[100][3];

int mp(int n);

int main()
{
    freopen("maximizePoints.in", "r", stdin);
    int n = 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &dp[i][j]);
        }
    }
    printf("%d\n", mp(n));
}

int mp(int n)
{
    for (int i = 1; i < n; i++)
    {
        dp[i][0] += max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += max(dp[i - 1][0], dp[i - 1][1]);
    }
    return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}