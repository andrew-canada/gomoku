#include <stdio.h>
#include <algorithm>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int n, m;
int line1[3005];
int line2[105];
int dp[3005][105][105][2];

int maxSugar(int p1, int l, int r, bool canTake);

int main()
{
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d", &line1[i]);
    }
    scanf("%d", &m);
    REP(i, 1, m)
    {
        scanf("%d", &line2[i]);
    }
    sort(line2, line2 + m + 1);
    printf("%d", maxSugar(1, 1, m, true));
}

int maxSugar(int p1, int l, int r, bool canTake)
{
    int sugar = 0;
    if (dp[p1][l][r][canTake])
    {
        return dp[p1][l][r][canTake];
    }
    if (p1 > n && l > r)
    {
        dp[p1][l][r][canTake] = sugar;
        return sugar;
    }
    if (canTake)
    {
        if (p1 <= n)
        {
            sugar = max(sugar, line1[p1] + maxSugar(p1 + 1, l, r, false));
            sugar = max(sugar, maxSugar(p1 + 1, l, r, true));
        }
        if (l <= r)
        {
            sugar = max(sugar, line2[r] + maxSugar(p1, l, r - 1, false));
        }
    }
    else
    {
        if (p1 <= n)
        {
            sugar = max(sugar, maxSugar(p1 + 1, l, r, true));
        }
        if (l <= r)
        {
            sugar = max(sugar, maxSugar(p1, l + 1, r, true));
        }
    }
    dp[p1][l][r][canTake] = sugar;
    return sugar;
}