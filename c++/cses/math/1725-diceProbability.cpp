#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 2e18

const int mxS = 600;

double dp[101][mxS + 1];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j <= 6 * i; j++)
        {
            for (int k = 1; k <= 6; k++)
            {
                dp[i + 1][j + k] += dp[i][j] / 6;
            }
        }
    }
    double ans = 0;
    for (int i = a; i <= b; i++)
    {
        ans += dp[n][i];
    }
    cout << fixed << setprecision(6) << ans;
}