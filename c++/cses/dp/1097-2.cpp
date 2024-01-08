#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 5e3;

int x[mxN + 1];
array<ll, 2> dp[mxN + 1][mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            array<ll, 2> cur;
            if (i == j)
            {
                cur = {x[i], 0};
            }
            else
            {
                if (dp[i + 1][j][1] + x[i] > dp[i][j - 1][1] + x[j])
                {
                    cur = {dp[i + 1][j][1] + x[i], dp[i + 1][j][0]};
                }
                else
                {
                    cur = {dp[i][j - 1][1] + x[j], dp[i][j - 1][0]};
                }
            }
            dp[i][j] = cur;
        }
    }
    cout << dp[0][n - 1][0];
}