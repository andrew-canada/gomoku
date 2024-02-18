/*
maximum flow on dense graph (ev^2)
1. build graph
    a) edge list with: node1, node2, capacity, flow
2. bfs: check if sink is reachable from source
    a) traverse graph using edge list
    b) find level of each node and store in level array
3. dfs: calculate flow through a path
    a) traverse graph until edge is saturated
4. repeat 2 and 3 until no flow from source to sink
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

const int mxN = 100;

struct edge
{
    int u, v, c, f;
    edge *rev;
    edge(int u1, int v1, int c1)
    {
        u = u1, v = v1, c = c1, f = 0;
    }
};

int n, m;
vector<edge *> adjL[mxN + 1];
int lvl[mxN + 1], nxt[mxN + 1];

void add(int u, int v, int c)
{
    edge *e1 = new edge(u, v, c);
    edge *e2 = new edge(v, u, 0);
    e1->rev = e2;
    e2->rev = e1;
    adjL[u].pb(e1);
    adjL[v].pb(e2);
}

bool bfs()
{
    queue<int> q;
    int cur;
    memset(lvl, INF, sizeof(lvl));
    q.push(1);
    lvl[1] = 0;
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
    return lvl[n] != INF;
}

int dfs(int u, int f)
{
    if (u == n)
    {
        return f;
    }
    while (nxt[u] < adjL[u].size())
    {
        edge *e = adjL[u][nxt[u]];
        if (lvl[e->v] == lvl[e->u] + 1 && e->c > e->f)
        {
            int cf = dfs(e->v, min(f, e->c - e->f));
            if (cf)
            {
                e->f += cf;
                e->rev->f -= cf;
                return cf;
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
        while (cur = dfs(1, INF))
        {
            ans += cur;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v >> c;
        add(u, v, c);
    }
    cout << dinic();
}

/*
6 7
1 2 2
1 3 4
2 4 1
2 5 1
3 5 7
4 6 10
5 6 5
*/