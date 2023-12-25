#include <bits/stdc++.h>

using namespace std;

int mk(int n, int c, int *v, int *w);

int dp[100][100];

int main()
{
    int n = 4;
    int c = 10;
    int v[4] = {1, 4, 3, 5};
    int w[4] = {4, 5, 6, 3};
    printf("%d\n", mk(n, c, v, w));
}

int mk(int n, int c, int *v, int *w)
{
    for (int j = 0; j <= c; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (w[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
        }
    }
    return dp[n][c];
}