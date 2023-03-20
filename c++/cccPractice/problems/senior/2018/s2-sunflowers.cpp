#include <stdio.h>

#define REPI(i, a, b) for (int i = int(a); i <= int(b - 1); i++)
#define REPD(i, a, b) for (int i = int(a); i >= int(b); i--)

int n;
int tl, tr, bl, br;
int data[105][105];

int main()
{
    scanf("%d", &n);
    REPI(i, 0, n)
    {
        REPI(j, 0, n)
        {
            scanf("%d", &data[i][j]);
        }
    }
    tl = data[0][0];
    tr = data[0][n - 1];
    bl = data[n - 1][0];
    br = data[n - 1][n - 1];

    if (tl <= tr && tl <= bl && tl <= br)
    {
        REPI(r, 0, n)
        {
            REPI(c, 0, n)
            {
                printf("%d ", data[r][c]);
            }
            printf("\n");
        }
    }
    else if (tr <= tl && tr <= bl && tr <= br)
    {
        REPD(c, n - 1, 0)
        {
            REPI(r, 0, n)
            {
                printf("%d ", data[r][c]);
            }
            printf("\n");
        }
    }
    else if (bl <= tl && bl <= tr && bl <= br)
    {
        REPI(c, 0, n)
        {
            REPD(r, n - 1, 0)
            {
                printf("%d ", data[r][c]);
            }
            printf("\n");
        }
    }
    else
    {
        REPD(c, n - 1, 0)
        {
            REPD(r, n - 1, 0)
            {
                printf("%d ", data[c][r]);
            }
            printf("\n");
        }
    }
}