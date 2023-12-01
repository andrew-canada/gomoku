/*
8 types: 4 groups, each group has positive and negative
supply and demand for each type is given
    1. negative accept negative
    2. positive accept either
    3. O accept O
    4. A accept A or O
    5. B accept B or O
    6. AB accept all
maximize blood receivers
*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

struct edge
{
    edge *back;
    int a, b, c, f;
    edge(int a1, int b1, int c1)
    {
        a = a1, b = b1, c = c1, f = 0;
    }
};

void add(int a, int b, int c);
bool bfs();
int dfs(int cur, int par);
int dinic();

const int INF = 0x3f3f3f3f;
vector<edge *> adjL[20];
int lvl[20], nxt[20];

int main()
{
    int val;
    REP(i, 1, 8)
    {
        scanf("%d", &val);
        add(0, i, val);
    }
    REP(i, 9, 16)
    {
        scanf("%d", &val);
        add(i, 17, val);
    }
    REP(i, 9, 16)
    {
        add(1, i, INF);
    }
    for (int i = 10; i <= 16; i += 2)
    {
        add(2, i, INF);
    }
    add(3, 11, INF), add(3, 12, INF), add(3, 15, INF), add(3, 16, INF), add(4, 12, INF), add(4, 16, INF);
    add(5, 13, INF), add(5, 14, INF), add(5, 15, INF), add(5, 16, INF), add(6, 14, INF), add(6, 16, INF);
    add(7, 15, INF), add(7, 16, INF), add(8, 16, INF);
    printf("%d\n", dinic());
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
            if (lvl[e->b] == INF && e->c - e->f > 0)
            {
                q.push(e->b);
                lvl[e->b] = lvl[cur] + 1;
            }
        }
    }
    return lvl[17] != INF;
}

int dfs(int cur, int f, int nxt[])
{
    if (cur == 17)
    {
        return f;
    }
    for (int n = adjL[cur].size(); nxt[cur] < n; nxt[cur]++)
    {
        edge *e = adjL[cur][nxt[cur]];
        if (e->c - e->f > 0 && lvl[e->b] == lvl[e->a] + 1)
        {
            int flow = dfs(e->b, min(f, e->c - e->f), nxt);
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

int dinic()
{
    int mf = 0;
    int f;
    while (bfs())
    {
        memset(nxt, 0, sizeof(nxt));
        while (f = dfs(0, INF, nxt))
        {
            mf += f;
        }
    }
    return mf;
}