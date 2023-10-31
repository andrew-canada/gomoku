#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define RREP(i, a, b) for (int i = int(a); i >= int(b); i--)
#define nd 1000005

int n, k;
int atr[nd], atrD[nd];
int maxAtrVal[nd];
ll dp[nd], rdp[nd];
ll maxDaySum[nd];

int main()
{
    scanf("%d%d", &n, &k);
    REP(i, 1, n)
    {
        scanf("%d", &atr[i]);
        atrD[i] = (k + i - 1) / k;
    }
    REP(i, 1, k)
    {
        dp[i] = maxAtrVal[i] = max(atr[i], maxAtrVal[i - 1]);
    }
    int maxAtr;
    for (int i = k + 1; i <= n; i += k)
    {
        maxAtr = 0;
        RREP(j, k * (atrD[i] - 1), k * (atrD[i] - 2))
        {
            maxDaySum[j] = max(maxDaySum[j + 1], dp[j] + maxAtr);
            rdp[j] = max(rdp[j + 1], dp[j]);
            maxAtr = max(maxAtr, atr[j]);
        }
        REP(j, i, min(n, i + k))
        {
            if (atrD[j] == atrD[j - 1])
            {
                maxAtrVal[j] = max(maxAtrVal[j - 1], atr[j]);
            }
            else
            {
                maxAtrVal[j] = atr[j];
            }
            dp[j] = max(maxDaySum[j - k], rdp[j - k] + maxAtrVal[j]);
        }
    }
    printf("%lld", dp[n]);
}