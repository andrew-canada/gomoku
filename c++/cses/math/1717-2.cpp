#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef unsigned long long ull;

const int M = 1e9 + 7, mxN = 1e6;

ull dp[mxN + 1];

int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (((i - 1) * dp[i - 1] % M) + ((i - 1) * dp[i - 2] % M)) % M;
    }
    cout << dp[n];
}