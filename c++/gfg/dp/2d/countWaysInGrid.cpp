#include <bits/stdc++.h>

using namespace std;

char grid[100][100];
int dp[100][100];

int nw(int r, int c);

int main()
{
    freopen("countWaysInGrid.in", "r", stdin);
    int r, c;
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            scanf(" %c", &grid[i][j]);
        }
    }
    printf("%d\n", nw(r, c));
}

int nw(int r, int c)
{
    dp[1][1] = 1;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (grid[i][j] == '#')
            {
                continue;
            }
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[r][c];
}