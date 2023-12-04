#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

struct edge
{
    edge *back;
    int a, b, c, f;
    edge(int a1, int b1, int c1)
    {
        a = a1, b = b1, c = c1, f = 0;
    }
};

vector<edge *> adjL[105];
int nxt[205], lvl[205];

void add(int a, int b, int c);
bool bfs();
bool dfs(int cur);
int dinic();

int n, m;

int main()
{
    int t;
    int val;
    scanf("%d", &t);
    while (t--)
    {
        memset(adjL, 0, sizeof(adjL));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            add(0, i, 1);
        }
        for (int i = n + 1; i <= n + m; i++)
        {
            add(i, n + m + 1, 1);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = n + 1; j <= n + m; j++)
            {
                scanf("%d", &val);
                if (val)
                {
                    add(i, j, INF);
                }
            }
        }
        printf("%d\n", dinic());
    }
    return 0;
}

void add(int a, int b, int c)
{
    edge *e1 = new edge(a, b, c);
    edge *e2 = new edge(b, a, 0);
    e1->back = e2;
    e2->back = e1;
    adjL[a].push_back(e1);
    adjL[b].push_back(e2);
}

bool bfs()
{
    int cur;
    queue<int> q;
    q.push(0);
    memset(lvl, INF, sizeof(lvl));
    lvl[0] = 0;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (edge *e : adjL[cur])
        {
            if (e->c - e->f > 0 && lvl[e->b] == INF)
            {
                q.push(e->b);
                lvl[e->b] = lvl[cur] + 1;
            }
        }
    }
    return lvl[n + m + 1] != INF;
}

bool dfs(int cur)
{
    if (cur == n + m + 1)
    {
        return 1;
    }
    for (int n = adjL[cur].size(); nxt[cur] < n; nxt[cur]++)
    {
        edge *e = adjL[cur][nxt[cur]];
        if (e->c - e->f > 0 && lvl[e->b] == lvl[e->a] + 1)
        {
            int flow = dfs(e->b);
            if (flow > 0)
            {
                e->f++;
                e->back->f--;
                return 1;
            }
        }
    }
    return 0;
}

int dinic()
{
    int mj = 0;
    while (bfs())
    {
        memset(nxt, 0, sizeof(nxt));
        while (dfs(0))
        {
            mj++;
        }
    }
    return mj;
}