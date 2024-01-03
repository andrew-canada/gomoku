#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 1e6;

int dp[mxN + 1];

int main()
{
    int n;
    cin >> n;
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int n1 = i;
        while (n1)
        {
            dp[i] = min(dp[i], dp[i - n1 % 10] + 1);
            n1 /= 10;
        }
    }
    cout << dp[n];
}