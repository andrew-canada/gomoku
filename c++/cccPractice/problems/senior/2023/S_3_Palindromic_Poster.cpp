/*
2d grid of lowercase english characters; n row, m col
generate grid with r palindrome rows and c palindrome cols
print IMPOSSIBLE if not possible
*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f

char grid[2005][2005];
int n, m, r, c;

bool update();

int main()
{
    scanf("%d%d%d%d", &n, &m, &r, &c);
    if (update())
    {
        REP(i, 0, n)
        {
            grid[i][m] = 0;
            puts(grid[i]);
        }
    }
    else
    {
        printf("IMPOSSIBLE");
    }
}

bool update()
{
    int npr, npc;
    memset(grid, 'a', sizeof(grid));
    if (n == r && m == c)
    {
        return true;
    }
    if (n == r)
    {
        npc = m - c;
        REP(l, 0, npc / 2)
        {
            grid[0][l] = grid[0][m - l - 1] = 'b';
        }
        if (npc % 2 == 1)
        {
            if (m % 2 == 1)
            {
                grid[0][m / 2] = 'b';
            }
            else
            {
                return false;
            }
        }
    }
    else if (m == c)
    {
        npr = n - r;
        REP(l, 0, npr / 2)
        {
            grid[l][0] = grid[n - l - 1][0] = 'b';
        }
        if (npr % 2 == 1)
        {
            if (n % 2 == 1)
            {
                grid[n / 2][0] = 'b';
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        REP(i, 0, n - r)
        {
            grid[i][0] = 'b';
        }
        REP(j, 0, m - c)
        {
            grid[0][j] = 'b';
        }
        grid[0][0] = 'c';
    }
    return true;
}