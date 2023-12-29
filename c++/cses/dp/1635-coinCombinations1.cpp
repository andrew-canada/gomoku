#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 0x3f3f3f3f

const int mxN = 100, mxX = 1e6, M = 1e9 + 7;

int c[mxN];
ll dp[mxX + 1];

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    REP(i, 0, n - 1)
    {
        scanf("%d", &c[i]);
    }
    dp[0] = 1;
    REP(i, 1, x)
    {
        REP(j, 0, n - 1)
        {
            if (i >= c[j])
            {
                dp[i] = (dp[i] + dp[i - c[j]]) % M;
            }
        }
    }
    printf("%lld", dp[x]);
}