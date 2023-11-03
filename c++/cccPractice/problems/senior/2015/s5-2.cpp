#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

using namespace std;

int n, m;
int line1[3005];
int line2[105];
int dp[3005][105][105][2];

int maxSugar(int p1, int l, int r, bool taken);

int main()
{
    scanf("%d%d", &n, &m);
    REP(i, 0, n)
    {
        scanf("%d", &line1[i]);
    }
    REP(i, 0, m)
    {
        scanf("%d", &line2[i]);
    }
    printf("%d", maxSugar(0, 0, 1, false));
}

int maxSugar(int p1, int l, int r, bool taken)
{
    if (dp[p1][l][r][taken])
    {
        return dp[p1][l][r][taken];
    }
    if (!taken)
    {
        if (l == m)
        {
            return dp[p1][l][r][taken] = maxSugar(p1 + 1, l, r, true);
        }
        }
}