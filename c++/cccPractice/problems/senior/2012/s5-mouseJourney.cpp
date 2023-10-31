#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int r, c;
int nc;
bool cat[26][26];
int dp[26][26];

int getPaths(int r, int c);

int main()
{
    scanf("%d%d%d", &r, &c, &nc);
    int x, y;
    REP(i, 0, nc)
    {
        scanf("%d%d", &x, &y);
        cat[x][y] = true;
    }
    printf("%d", getPaths(r, c));
}

int getPaths(int r, int c)
{
    if (dp[r][c])
    {
        return dp[r][c];
    }
    if (r == 1 && c == 1)
    {
        return 1;
    }
    if (cat[r][c])
    {
        return 0;
    }
    int numPaths = 0;
    if (r > 1)
    {
        numPaths += getPaths(r - 1, c);
    }
    if (c > 1)
    {
        numPaths += getPaths(r, c - 1);
    }
    dp[r][c] = numPaths;
    return numPaths;
}