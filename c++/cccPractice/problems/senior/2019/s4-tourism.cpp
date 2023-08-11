#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int n, k;
int ad;
int totDays;
int atr[1000005];
int maxScore[1000005];
int dp[1000005];

int main()
{
    scanf("%d%d", &n, &k);
    REP(i, 1, n)
    {
        scanf("%d", atr[i]);
    }
    ad = n % k;
    if (ad % k == 0)
    {
        ad = k;
    }
    totDays = (n + k - 1) / k;
    REP(i, 1, k)
    {
        maxScore[i] = MAX(maxScore[i - 1], atr[i]);
        dp[i] = maxScore[i];
    }
    REP(i, 1, totDays - 1)
    {
        REP(j, k * i, MIN(k * (i + 1) - 1, n))
        {
            maxScore[j] = ((j > k * i) ? MAX(maxScore[j - 1], atr[j]) : atr[j]);
        }
    }
}
