#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e3, M = 1e9 + 7;

ll dp[mxN + 1][mxN + 1];
string grid[mxN + 1];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
            {
                dp[i][j] = 0;
                continue;
            }
            if (j)
            {
                dp[i][j] += dp[i][j - 1];
            }
            if (i)
            {
                dp[i][j] += dp[i - 1][j];
            }
            dp[i][j] %= M;
        }
    }
    cout << dp[n - 1][n - 1];
}