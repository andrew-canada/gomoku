#include <stdio.h>
#include <queue>
#include <math.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int r, c;
int grid[1005][1005];
bool vis[1000005];
queue<int> q;

int main()
{
    scanf("%d%d", &r, &c);
    REP(i, 1, r)
    {
        REP(j, 1, c)
        {
            scanf("%d", &grid[i][j]);
        }
    }
    int cur = grid[1][1];
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (!vis[cur])
        {
            int j;
            int nxt;
            vis[cur] = true;
            REP(i, 1, sqrt(cur))
            {
                j = cur / i;
                if (i * j == cur)
                {
                    if (i == r && j == c || i == c && j == r)
                    {
                        printf("yes");
                        return 0;
                    }
                    if (i <= r && j <= c)
                    {
                        nxt = grid[i][j];
                        if (!vis[nxt])
                        {
                            q.push(nxt);
                        }
                    }
                    if (i <= c && j <= r)
                    {
                        nxt = grid[j][i];
                        if (!vis[nxt])
                        {
                            q.push(nxt);
                        }
                    }
                }
            }
        }
    }
    printf("no");
}