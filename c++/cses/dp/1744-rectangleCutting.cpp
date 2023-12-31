#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f

const int mxA = 500;

ll dp[mxA + 1][mxA + 1];

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
            for (int v = 1; v < j; v++)
            {
                dp[i][j] = min(dp[i][j], dp[i][v] + dp[i][j - v] + 1);
            }
            for (int r = 1; r < i; r++)
            {
                dp[i][j] = min(dp[i][j], dp[r][j] + dp[i - r][j] + 1);
            }
        }
    }
    cout << dp[a][b] << '\n';
}