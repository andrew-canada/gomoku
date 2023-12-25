#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int grid[1005][1005];
bool vis[1000005];
queue<int> q;

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    REP(r, 1, m)
    {
        REP(c, 1, n)
        {
            scanf("%d", &grid[r][c]);
        }
    }
    vis[grid[1][1]] = true;
    q.push(grid[1][1]);
    int cur;
    int j;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        REP(i, 1, sqrt(cur))
        {
            j = cur / i;
            if (i * j != cur)
            {
                continue;
            }
            if (i == m && j == n || j == m && i == n)
            {
                printf("yes");
                return 0;
            }
            if (i <= m && j <= n && !vis[grid[i][j]])
            {
                vis[grid[i][j]] = true;
                q.push(grid[i][j]);
            }
            if (j <= m && i <= n && !vis[grid[j][i]])
            {
                vis[grid[j][i]] = true;
                q.push(grid[j][i]);
            }
        }
    }
    printf("no");
}