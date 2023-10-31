#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n;
int rb[405];
int mb;
int dp[405][405];
int psa[405];

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &rb[i]);
        dp[i][i] = rb[i];
        psa[i] = rb[i] + psa[i - 1];
        mb = max(mb, rb[i]);
    }
    int r;
    int i, j;
    REP(len, 2, n + 1)
    {
        REP(l, 0, n - len + 1)
        {
            r = l + len - 1;
            i = l, j = r;
            while (i + 1 <= j)
            {
                if (dp[l][i] && dp[l][i] == dp[j][r] && (i + 1 == j || dp[i + 1][j - 1]))
                {
                    dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][j - 1] + dp[j][r]);
                    mb = max(mb, dp[l][r]);
                    break;
                }
                if (psa[i] - psa[l - 1] > psa[r] - psa[j - 1])
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