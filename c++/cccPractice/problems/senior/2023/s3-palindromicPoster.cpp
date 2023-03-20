#include <stdio.h>
#include <cstring>
#include <algorithm>

// #define LOCAL
#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

int r, c, pr, pc;
bool flip;
char poster[2005][2005];

int main()
{
#ifdef LOCAL
    freopen("s3.in", "r", stdin);
    freopen("s3.out", "w", stdout);
#endif
    scanf("%d %d %d %d", &r, &c, &pr, &pc);
    memset(poster, 'a', sizeof(poster));
    if (c == pc)
    {
        std::swap(c, r);
        std::swap(pc, pr);
        flip = true;
    }
    if (pr == r)
    {
        int npc = c - pc;
        REP(i, 0, npc / 2)
        {
            poster[0][i] = 'b';
            poster[0][c - i - 1] = 'b';
        }
        if (npc % 2 == 1)
        {
            if (c % 2 == 1)
            {
                poster[0][c / 2] = 'b';
            }
            else
            {
                printf("IMPOSSIBLE");
                return 0;
            }
        }
    }
    else
    {
        REP(i, 0, r - pr)
        {
            poster[i][0] = 'b';
        }
        REP(i, 0, c - pc)
        {
            poster[0][i] = 'b';
        }
        poster[0][0] = 'c';
    }

    if (flip)
    {
        std::swap(r, c);
        REP(i, 0, std::max(r, c))
        {
            REP(j, 0, i)
            {
                std::swap(poster[i][j], poster[j][i]);
            }
        }
    }

    REP(i, 0, r)
    {
        poster[i][c] = 0;
        puts(poster[i]);
    }
}