#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
int p[3005];
int np[105];
int ms;
int dp[3005][105][105][2];

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int getSugar(int lineP, int left, int right, bool canTake);

int main()
{
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d", &p[i]);
    }
    scanf("%d", &m);
    REP(i, 1, m)
    {
        scanf("%d", &np[i]);
    }
    sort(np, np + m + 1);
    printf("%d", getSugar(1, 1, m, true));
}

int getSugar(int lineP, int left, int right, bool canTake)
{
    int maxSugar = 0;
    if (dp[lineP][left][right][canTake])
    {
        return dp[lineP][left][right][canTake];
    }
    if (lineP == n + 1 && left > right)
    {
        dp[lineP][left][right][canTake] = maxSugar;
        return maxSugar;
    }
    if (canTake)
    {
        if (lineP <= n)
        {
            maxSugar = max(maxSugar, p[lineP] + getSugar(lineP + 1, left, right, false));
            maxSugar = max(maxSugar, getSugar(lineP + 1, left, right, true));
        }
        if (left <= right)
        {
            maxSugar = max(maxSugar, np[right] + getSugar(lineP, left, right - 1, false));
        }
    }
    else
    {
        if (lineP <= n)
        {
            maxSugar = max(maxSugar, getSugar(lineP + 1, left, right, true));
        }
        if (left <= right)
        {
            maxSugar = max(maxSugar, getSugar(lineP, left + 1, right, true));
        }
    }
    dp[lineP][left][right][canTake] = maxSugar;
    return maxSugar;
}