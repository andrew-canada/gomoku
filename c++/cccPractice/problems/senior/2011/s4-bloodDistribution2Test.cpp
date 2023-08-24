#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INF 1000000000

struct edge
{
    int from, to, cap, flow;
    edge *residual;
    edge(int f, int t, int c)
    {
        from = f;
        to = t;
        cap = c;
        flow = 0;
    }
};

int maxFl;
int lvl[20];
vector<edge> el[20];

void addE(int from, int to, int cap);
int dfs(int cur, int nxt[], int flow);
bool bfs();
int dinic();

int main()
{
    freopen("s4.in", "r", stdin);
    freopen("s4.out", "w", stdout);
    int cap;
    REP(i, 1, 8)
    {
        scanf("%d", &cap);
        addE(0, i, cap);
    }
    REP(i, 9, 16)
    {
        scanf("%d", &cap);
        addE(i, 17, cap);
    }
    REP(i, 9, 16)
    {
        addE(1, i, el[i][0].cap);
    }
    for (int i = 10; i <= 16; i += 2)
    {
        addE(2, i, el[i][0].cap);
    }
    // a-
    addE(3, 11, el[11][0].cap), addE(3, 12, el[12][0].cap), addE(3, 15, el[15][0].cap), addE(3, 16, el[16][0].cap);
    // a+
    addE(4, 12, el[12][0].cap), addE(4, 16, el[16][0].cap);
    // b-
    addE(5, 13, el[13][0].cap), addE(5, 14, el[14][0].cap), addE(5, 15, el[15][0].cap), addE(5, 16, el[16][0].cap);
    // b+
    addE(6, 14, el[14][0].cap), addE(6, 16, el[16][0].cap);
    // ab-
    addE(7, 15, el[15][0].cap), addE(7, 16, el[16][0].cap);
    // ab+
    addE(8, 16, el[16][0].cap);
    printf("%d", dinic());
}

void addE(int from, int to, int cap)
{
    edge *e1 = new edge(from, to, cap);
    edge *e2 = new edge(to, from, 0);
    e1->residual = e2;
    e2->residual = e1;
    el[from].push_back(*e1);
    el[to].push_back(*e2);
}

int dfs(int cur, int nxt[], int flow)
{
    if (cur == 17)
    {
        return flow;
    }
    int ne = el[cur].size();
    for (; nxt[cur] < ne; nxt[cur]++)
    {
        edge &curE = el[cur][nxt[cur]];
        int remCap = curE.cap - curE.flow;
        if (remCap > 0 && lvl[curE.to] == lvl[cur] + 1)
        {
            int bn = dfs(curE.to, nxt, MIN(flow, remCap));
            if (bn > 0)
            {
                curE.flow += bn;
                curE.residual->flow += bn;
                return bn;
            }
        }
    }
    return 0;
}

bool bfs()
{
    memset(lvl, -1, sizeof(lvl));
    lvl[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (edge e : el[cur])
        {
            int cap = e.cap - e.flow;
            if (cap > 0 && lvl[e.to] == -1)
            {
                lvl[e.to] = lvl[cur] + 1;
                q.push(e.to);
            }
        }
    }
    REP(i, 0, 17)
    {
        printf("%d ", lvl[i]);
    }
    printf("\n");
    return lvl[17] != -1;
}

int dinic()
{
    int nxt[20];
    while (bfs())
    {
        memset(nxt, 0, sizeof(nxt));
        while (int fl = dfs(0, nxt, INF))
        {
            maxFl += fl;
        }
    }
    return maxFl;
}