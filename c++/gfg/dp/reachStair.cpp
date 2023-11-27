#include <bits/stdc++.h>

using namespace std;

int dp[100];

int nw(int n)
{
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n = 4;
    printf("%d\n", nw(n));
}