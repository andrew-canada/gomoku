#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e5, mxX = 100, M = 1e9 + 7;

int n, m;
int dp[mxN + 1][mxX + 1];
int arr[mxN + 1];

bool isSafe(int n1)
{
    return n1 > 0 && n1 <= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (arr[0] == 0)
    {
        fill(dp[0], dp[0] + n, 1);
    }
    dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] += dp[i - 1][j];
                if (j > 1)
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                if (j < m)
                {
                    dp[i][j] += dp[i - 1][j + 1];
                }
                dp[i][j] %= M;
            }
        }
        else
        {
            dp[i][arr[i]] += dp[i - 1][arr[i]];
            if (arr[i] > 1)
            {
                dp[i][arr[i]] += dp[i - 1][arr[i] - 1];
            }
            if (arr[i] < m)
            {
                dp[i][arr[i]] += dp[i - 1][arr[i] + 1];
            }
            dp[i][arr[i]] %= M;
        }
    }
    int numArr = 0;
    for (int i = 1; i <= m; i++)
    {
        numArr += dp[n - 1][i];
        numArr %= M;
    }
    cout << numArr;
}