#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxA = 500;

int dp[mxA + 1][mxA + 1];

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i ^ j)
            {
                dp[i][j] = INF;
            }
            for (int r = 1; r <= i; r++)
            {
                dp[i][j] = min(dp[i][j], dp[r][j] + dp[i - r][j] + 1);
            }
            for (int c = 1; c <= j; c++)
            {
                dp[i][j] = min(dp[i][j], dp[i][c] + dp[i][j - c] + 1);
            }
        }
    }
    cout << dp[a][b] << '\n';
}