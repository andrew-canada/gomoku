#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MN 1000005

int n;
int fav[MN];
int last[MN];
double dp[MN];
double totProb;

int main()
{
    // freopen("s5.in", "r", stdin);
    scanf("%d", &n);
    REP(i, 0, n - 1)
    {
        scanf("%d", &fav[i]);
    }
    if (fav[0] == fav[n - 1])
    {
        printf("1");
        return 0;
    }
    last[fav[n - 1]] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (fav[i] == fav[0])
        {
            dp[i] = 1;
        }
        else if (last[fav[i]])
        {
            dp[i] = dp[last[fav[i]]];
        }
        else
        {
            dp[i] = (1 + totProb) / (n - i);
        }
        printf("%lf\n", dp[i]);
        totProb += dp[i];
        if (!last[fav[i]])
        {
            last[fav[i]] = i;
        }
    }
    printf("%.8f", totProb / n);
}