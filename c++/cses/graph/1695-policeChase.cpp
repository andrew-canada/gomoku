#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 5e2, mxM = 1e3, M = 1e9 + 7;

struct edge
{
    edge *back;
    ll u, v, c, f;
    edge(ll u1, ll v1, ll c1)
    {
        u = u1, v = v1, c = c1, f = 0;
    }
};

vector<edge *> adjL[mxN];
int lvl[mxN], nxt[mxN];
int n, m;

void add(int u, int v, int c)
{
    edge *e1 = new edge(u, v, c);
    edge *e2 = new edge(v, u, 0);
    e1->back = e2;
    e2->back = e1;
    adjL[u].push_back(e1);
    adjL[v].push_back(e2);
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
        for (edge *e : adjL[cur])
        {
            if (lvl[e->v] == INF && e->c - e->f > 0)
            {
                q.push(e->v);
                lvl[e->v] = lvl[cur] + 1;
            }
        }
    }
    return lvl[n - 1] != INF;
}

ll dfs(int cur, ll f)
{
    if (cur == n - 1)
    {
        return f;
    }
    for (int num = adjL[cur].size(); nxt[cur] < num; nxt[cur]++)
    {
        edge *e = adjL[cur][nxt[cur]];
        if (e->c - e->f > 0 && lvl[e->v] == lvl[e->u] + 1)
        {
            ll flow = dfs(e->v, min(f, e->c - e->f));
            if (flow > 0)
            {
                e->f += flow;
                e->back->f -= flow;
                return flow;
            }
        }
    }
    return 0;
}

ll dinic()
{
    ll mf = 0, f;
    while (bfs())
    {
        memset(nxt, 0, sizeof(nxt));
        while (f = dfs(0, INF))
        {
            mf += f;
        }
    }
    return mf;
}

int main()
{
    cin >> n >> m;
    int u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c, --u, --v;
        add(u, v, c);
    }
    cout << dinic();
}