#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

const int mxN = 20;

struct edge
{
    int u, v, c, f;
    edge *rev;
    edge(int u1, int v1, int c1)
    {
        u = u1, v = v1, c = c1, f = 0;
    }
};

vector<edge *> adjL[mxN];
int lvl[mxN], nxt[mxN];

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
    q.push(0);
    memset(lvl, INF, sizeof(lvl));
    lvl[0] = 0;
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (const edge *e : adjL[cur])
        {
            if (lvl[e->v] == INF && e->c > e->f)
            {
                lvl[e->v] = lvl[e->u] + 1;
                q.push(e->v);
            }
        }
    }
    return lvl[17] != INF;
}

int dfs(int cur = 0, int flow = INF)
{
    if (cur == 17)
    {
        return flow;
    }
    while (nxt[cur] < adjL[cur].size())
    {
        edge *e = adjL[cur][nxt[cur]];
        if (e->c > e->f && lvl[e->v] == lvl[e->u] + 1)
        {
            int ans = dfs(e->v, min(flow, e->c - e->f));
            if (ans > 0)
            {
                e->f += ans;
                e->rev->f -= ans;
                return ans;
            }
        }
        nxt[cur]++;
    }
    return 0;
}

int dinic()
{
    int ans = 0, cur;
    while (bfs())
    {
        memset(nxt, 0, sizeof(nxt));
        while (cur = dfs())
        {
            ans += cur;
        }
    }
    return ans;
}

int main()
{
    // 0 is source, 17 is sink
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