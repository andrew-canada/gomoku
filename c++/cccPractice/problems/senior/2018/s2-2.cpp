#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define RREP(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)

int n;
int t[105][105];

int main()
{
    scanf("%d", &n);
    int tl, tr, bl, br;
    REP(i, 0, n)
    {
        REP(j, 0, n)
        {
            scanf("%d", &t[i][j]);
        }
    }
    tl = t[0][0], tr = t[0][n - 1], bl = t[n - 1][0], br = t[n - 1][n - 1];
    if (tl <= tr && tl <= bl && tl <= br)
    {
        REP(i, 0, n)
        {
            REP(j, 0, n)
            {
                printf("%d ", t[i][j]);
            }
            printf("\n");
        }
    }
    else if (tr <= tl && tr <= bl && tr <= br)
    {
        RREP(j, n, 0)
        {
            REP(i, 0, n)
            {
                printf("%d ", t[i][j]);
            }
            printf("\n");
        }
    }
    else if (bl <= tl && bl <= tr && bl <= br)
    {
        REP(j, 0, n)
        {
            RREP(i, n, 0)
            {
                printf("%d ", t[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        RREP(i, n, 0)
        {
            RREP(j, n, 0)
            {
                printf("%d ", t[i][j]);
            }
            printf("\n");
        }
    }
}