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
            while (i <= j)
            {
                if (dp[l][i - 1] && dp[l][i - 1] == dp[j][r] && (i == j || dp[i][j - 1]))
                {
                    dp[l][r] = max(dp[l][r], dp[l][i - 1] + dp[i][j - 1] + dp[j][r]);
                    mb = max(mb, dp[l][r]);
                    break;
                }
                if (psa[i - 1] - psa[l - 1] > psa[r] - psa[j - 1])
                {
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
    }
    printf("%d", mb);
}