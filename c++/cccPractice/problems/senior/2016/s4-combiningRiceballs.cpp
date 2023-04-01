#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define max(a, b) a > b ? a : b

int n;
int dp[405][405];
int psa[405];
int val;
int mb;

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &val);
        dp[i][i] = val;
        psa[i] = val + psa[i - 1];
        mb = max(mb, val);
    }
    REP(len, 2, n + 1)
    {
        REP(l, 0, n - len + 1)
        {
            int r = l + len - 1;
            int i = l + 1;
            int j = r;
            while (j <= i)
            {
                if (dp[l][i - 1] && dp[l][i - 1] == dp[j][r] &&)
                {
                    dp[l][r] = max(dp[l][r], );
                    mb = max(mb, dp[l][r]);
                }
                if (dp[i - 1] - dp[l - 1] > dp[r] - dp[j - 1])
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
        }
    }
    printf("%d", mb);
}