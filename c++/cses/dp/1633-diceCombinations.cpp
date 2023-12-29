#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int M = 1e9 + 7, maxn = 1e6;

ll dp[maxn + 5];

int main()
{
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    REP(i, 1, n)
    {
        REP(j, 1, min(6, i))
        {
            dp[i] = (dp[i] + dp[i - j]) % M;
        }
    }
    printf("%lld\n", dp[n]);
}