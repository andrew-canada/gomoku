#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define RREP(i, a, b) for (int i = int(a); i >= int(b); i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int n, k;
int lastDay;
int totDays;
int atr[1000005];
int pref[1000005];
int suf[1000005];
int dp[1000005];

int main()
{
    scanf("%d%d", &n, &k);
    REP(i, 1, n)
    {
        scanf("%d", &atr[i]);
    }
    lastDay = (n % k == 0) ? k : n % k;
    totDays = (n + k - 1) / k;
    REP(i, 1, k)
    {
        pref[i] = MAX(pref[i - 1], atr[i]);
        dp[i] = pref[i];
    }
    RREP(i, k, 1)
    {
        suf[i] = MAX(suf[i + 1], atr[i]);
        dp[i] = MAX(dp[i], suf[i] + (i < k ? dp[i + 1] : 0));
    }
    REP(i, 1, totDays - 1)
    {
        REP(j, k * i + 1, MIN(k * (i + 1), n))
        {
            // pref[j] = ((j > k * i) ? MAX(pref[j - 1], atr[j]) : atr[j]);
            pref[j] = MAX(pref[j - 1], atr[j]);
        }
        REP(j, MIN(n, k * (i + 1)), k * i + 1)
        {
            // suf[j] = ((j < MIN(n, k * (i + 1) - 1)) ? suf[i] = MAX(suf[j + 1], atr[j]) : atr[j]);
            suf[j] = MAX(suf[j + 1], atr[j]);
            dp[j] = MAX(dp[j], suf[j] + (j < MIN(n, k * (i + 1)) ? dp[i + 1] : 0));
        }
    }
    printf("%d", dp[totDays]);
}
