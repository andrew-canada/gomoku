#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxX = 1e6, M = 1e9 + 7;

int dp[mxX + 1], coin[101];

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= coin[j])
            {
                dp[i] = (dp[i] + dp[i - coin[j]]) % M;
            }
        }
    }
    cout << dp[x];
}