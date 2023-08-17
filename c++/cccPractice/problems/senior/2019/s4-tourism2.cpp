#include <stdio.h>

typedef long long ll;

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
ll dp[1000005];
ll revSum[1000005];
ll revDP[1000005];

int main()
{
    // freopen("s4.in", "r", stdin);
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
        revSum[i] = MAX(suf[i] + dp[i - 1], revSum[i + 1]);
        revDP[i] = MAX(dp[i], revDP[i + 1]);
    }
    REP(i, 1, totDays - 1)
    {
        REP(j, k * i + 1, MIN(n, k * (i + 1)))
        {
            pref[j] = (j > k * i + 1) ? MAX(pref[j - 1], atr[j]) : atr[j];
        }
        RREP(j, MIN(n, k * (i + 1)), k * i + 1)
        {
            suf[j] = (j < MIN(n, k * (i + 1))) ? MAX(suf[j + 1], atr[j]) : atr[j];
        }
        int curDayIdxOfLastAttr = k * (i - 1) + lastDay;
        // int nextDayIdxOfLastAttr = curDayIdxOfLastAttr + k;
        // if (curDayIdxOfLastAttr < k * nextDayIdxOfLastAttr && nextDayIdxOfLastAttr <= n)
        // {
        //     dp[nextDayIdxOfLastAttr] = MAX(pref[nextDayIdxOfLastAttr] + revDP[curDayIdxOfLastAttr], revSum[curDayIdxOfLastAttr + 1]);
        // }
        for (int nextDayIdxOfLastAttr = curDayIdxOfLastAttr + k; nextDayIdxOfLastAttr <= curDayIdxOfLastAttr + k && curDayIdxOfLastAttr < k * i && nextDayIdxOfLastAttr <= n; nextDayIdxOfLastAttr++)
        {
            dp[nextDayIdxOfLastAttr] = MAX(pref[nextDayIdxOfLastAttr] + revDP[curDayIdxOfLastAttr], revSum[curDayIdxOfLastAttr + 1]);
            curDayIdxOfLastAttr += (nextDayIdxOfLastAttr - curDayIdxOfLastAttr == k);
        }
        RREP(j, MIN(n, k * (i + 1)), k * i + 1)
        {
            revSum[j] = MAX(suf[j] + dp[j - 1], j < MIN(n, k * (i + 1)) ? revSum[j + 1] : 0);
            revDP[j] = MAX(dp[j], j < MIN(n, k * (i + 1)) ? revDP[j + 1] : 0);
        }
    }
    printf("%lld", dp[n]);
}
