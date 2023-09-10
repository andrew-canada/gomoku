#include <stdio.h>
#include <cstring>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, m, r, c;
char poster[2005][2005];

int main()
{
    scanf("%d%d%d%d", &n, &m, &r, &c);
    memset(poster, 'a', sizeof(poster));
    if (n == r)
    {
        int npc = m - c;
        if (npc % 2 == 1)
        {
            if (m % 2 == 1)
            {
                poster[0][m / 2] = 'b';
            }
            else
            {
                printf("IMPOSSIBLE");
                return 0;
            }
        }
        REP(dist, 0, npc / 2)
        {
            poster[0][dist] = poster[0][m - dist - 1] = 'b';
        }
    }
    else if (m == c)
    {
        int npr = n - r;
        if (npr % 2 == 1)
        {
            if (n % 2 == 1)
            {
                poster[n / 2][0] = 'b';
            }
            else
            {
                puts("IMPOSSIBLE");
                return 0;
            }
        }
        REP(dist, 0, npr / 2)
        {
            poster[dist][0] = poster[n - dist - 1][0] = 'b';
        }
    }
    else
    {
        REP(i, 0, n - r)
        {
            poster[i][0] = 'b';
        }
        REP(i, 0, m - c)
        {
            poster[0][i] = 'b';
        }
        poster[0][0] = 'c';
    }
    REP(i, 0, n)
    {
        poster[i][m] = 0;
        puts(poster[i]);
    }
}