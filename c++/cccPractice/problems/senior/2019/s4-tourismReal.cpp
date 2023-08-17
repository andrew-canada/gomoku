#include <stdio.h>

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define RREP(i, a, b) for (int i = int(a); i >= int(b); i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define nd 1000005

int n, k;
int totDays;
int atr[nd];
int pa[nd];
int atrDays[nd];
ll dp[nd];
ll revDP[nd];
ll maxDaySum[nd];

int main()
{
    // freopen("s4.in", "r", stdin);
    scanf("%d%d", &n, &k);
    REP(i, 1, n)
    {
        scanf("%d", &atr[i]);
        atrDays[i] = (i + k - 1) / k;
    }
    REP(i, 1, k)
    {
        dp[i] = pa[i] = MAX(pa[i - 1], atr[i]);
    }
    for (int i = k + 1; i <= n; i += k)
    {
        int suf = 0;
        RREP(j, k * (atrDays[i] - 1), k * (atrDays[i] - 2) + 1)
        {
            revDP[j] = MAX(revDP[j + 1], dp[j]);
            maxDaySum[j] = MAX(maxDaySum[j + 1], dp[j] + suf);
            suf = MAX(suf, atr[j]);
        }
        REP(j, i, MIN(i + k, n))
        {
            if (atrDays[j] == atrDays[j - 1])
            {
                pa[j] = MAX(pa[j - 1], atr[j]);
            }
            else
            {
                pa[j] = atr[j];
            }
            dp[j] = MAX(pa[j] + revDP[j - k], maxDaySum[j - k]);
        }
    }
    printf("%lld", dp[n]);
}