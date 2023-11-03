#include <stdio.h>
#include <algorithm>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

using namespace std;

int n, m;
int line1[3005];
int line2[105];
int dp[3005][105][105][2];

int maxSugar(int p1, int l, int r, bool canTake);

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
    sort(line2, line2 + m);
    printf("%d", maxSugar(0, 0, 1, false));
}

int maxSugar(int p1, int l, int r, bool canTake)
{
    int sugar = 0;
    if (dp[p1][l][r][canTake])
    {
        return dp[p1][l][r][canTake];
    }
    if (l > r)
    {
    }
    if (canTake)
    {
        if (l == m)
        {
            return dp[p1][l][r][canTake] = maxSugar(p1 + 1, l, r, true);
        }
        return dp[p1][l][r][canTake] = max(dp[p1][l][r][canTake], maxSugar(p1, l, r, false));
    }
    else
    {
    }
}