#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INF 1000000000

int blood;
int adjL[20][20];
int lvl[20];
int vis[20];
int nxt[20];

bool bfs();

int dfs(int cur, int flow);

int main()
{
    REP(i, 1, 8)
    {
        scanf("%d", &adjL[0][i]);
    }
    REP(i, 9, 16)
    {
        scanf("%d", &adjL[i][17]);
    }
    REP(i, 9, 16)
    {
        adjL[1][i] = INF;
    }
    for (int i = 10; i <= 16; i += 2)
    {
        adjL[2][i] = INF;
    }
    adjL[3][12] = adjL[3][11] = adjL[3][15] = adjL[3][16] = adjL[4][12] = adjL[4][16] = adjL[5][13] = INF;
    adjL[5][14] = adjL[5][15] = adjL[5][16] = adjL[6][14] = adjL[6][16] = adjL[7][15] = adjL[7][16] = adjL[8][16] = INF;
    int curBlood;

    while (bfs())
    {
        while (curBlood = dfs(0, INF))
        {
            blood += curBlood;
        }
    }
    printf("%d", blood);
}

bool bfs()
{
    memset(lvl, INF, sizeof(lvl));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(0);
    vis[0] = true;
    lvl[0] = 0;
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        REP(i, 0, 17)
        {
            if (adjL[cur][i] > 0 && !vis[i] && cur != i)
            {
                lvl[i] = lvl[cur] + 1;
                q.push(i);
                vis[i] = true;
            }
        }
    }
    if (lvl[17] == INF)
    {
        return false;
    }
    return true;
}

int dfs(int cur, int flow)
{
    if (cur == 17)
    {
        return flow;
    }
    REP(i, 0, 17)
    {
        if (adjL[cur][i] > 0)
        {
            if (lvl[i] == lvl[cur] + 1)
            {
                int curFlow = MIN(flow, adjL[cur][i]);
                int bn = dfs(i, curFlow);
                if (bn > 0)
                {
                    adjL[cur][i] -= bn;
                    adjL[i][cur] += bn;
                    return bn;
                }
            }
        }
    }
    return 0;
}