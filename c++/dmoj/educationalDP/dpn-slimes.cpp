#include <stdio.h>
#include <cstring>

#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)
#define min(a, b) a < b ? a : b

typedef long long ll;

int n;

ll dp[405][405];
ll psa[405];

int main()
{
    scanf("%d", &n);
    memset(dp, 2147483647, sizeof(dp));
    REP(i, 0, n)
    {
        scanf("%d", &psa[i]);
        psa[i] += psa[i - 1];
    }
    REP(len, 2, n + 1)
    {
        REP(l, 0, n - len + 1)
        {
            ll r = l + len - 1;
            REP(i, l, r + 1)
            {
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i][r]);
            }
            dp[l][r] += psa[r] - psa[l];
        }
    }
    printf("%d", dp[0][n - 1]);
}