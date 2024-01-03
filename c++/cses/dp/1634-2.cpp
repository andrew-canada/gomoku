#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxX = 1e6;

int dp[mxX + 1], coin[101];

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j >= coin[i])
            {
                dp[j] = min(dp[j], dp[j - coin[i]] + 1);
            }
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]);
}