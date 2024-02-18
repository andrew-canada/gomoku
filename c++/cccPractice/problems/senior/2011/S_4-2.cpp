#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

// 0 is source, 17 is sink
const int mxN = 18;

struct edge
{
    int u, v, c, f;
    edge *rev;
    edge(int u1, int v1, int c1)
    {
        u = u1, v = v1, c = c1, f = 0;
    }
};

vector<edge *> adjL[mxN + 1];
int lvl[mxN + 1], nxt[mxN + 1];

void add(int u, int v, int c)
{
    edge *e1 = new edge(u, v, c);
    edge *e2 = new edge(v, u, 0);
    e1->rev = e2, e2->rev = e1;
    adjL[u].pb(e1), adjL[v].pb(e2);
}

bool bfs()
{
    queue<int> q;
    int cur;
    memset(lvl, INF, sizeof(lvl));
    lvl[0] = 0;
    q.push(0);
    while (q.size())
    {
        cur = q.front();
        q.pop();
        for (const edge *e : adjL[cur])
        {
            if (lvl[e->v] == INF && e->c > e->f)
            {
                lvl[e->v] = lvl[cur] + 1;
                q.push(e->v);
            }
        }
    }
    return lvl[17] != INF;
}

int dfs(int u, int f)
{
    if (u == 17)
    {
        return f;
    }
    while (nxt[u] < adjL[u].size())
    {
        edge *e = adjL[u][nxt[u]];
        if (lvl[e->v] == lvl[e->u] + 1 && e->c > e->f)
        {
            int cur = dfs(e->v, min(f, e->c - e->f));
            if (cur)
            {
                e->f += cur;
                e->rev->f -= cur;
                return cur;
            }
        }
        nxt[u]++;
    }
    return 0;
}

int dinic()
{
    int cur, ans = 0;
    while (bfs())
    {
        memset(nxt, 0, sizeof(nxt));
        while (cur = dfs(0, INF))
        {
            ans += cur;
        }
    }
    return ans;
}

int main()
{
    int c;
    for (int i = 1; i <= 8; i++)
    {
        cin >> c;
        add(0, i, c);
    }
    for (int i = 9; i <= 16; i++)
    {
        cin >> c;
        add(i, 17, c);
    }
    for (int i = 9; i <= 16; i++)
    {
        add(1, i, INF);
        if (i % 2 == 0)
        {
            add(2, i, INF);
        }
    }
    add(3, 11, INF), add(3, 12, INF), add(3, 15, INF), add(3, 16, INF);
    add(4, 12, INF), add(4, 16, INF);
    add(5, 13, INF), add(5, 14, INF), add(5, 15, INF), add(5, 16, INF);
    add(6, 14, INF), add(6, 16, INF);
    add(7, 15, INF), add(7, 16, INF);
    add(8, 16, INF);
    cout << dinic();
}