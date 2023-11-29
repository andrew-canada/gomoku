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
int dfs(int cur, int par);
int bfs(int cur, int par);
int dinic();

vector<edge *> adjL[20];
const int INF = 0x3f3f3f3f;

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
    edge *e2 = new edge(b, a, c);
    e1->back = e2;
    e2->back = e1;
    adjL[a].push_back(e1);
    adjL[b].push_back(e2);
}

int dfs(int cur, int par)
{
}

int bfs(int cur, int par)
{
    queue<edge> q;
    queue ct;
}

int dinic()
{
    int patients = 0;
    int type;
    while (type = bfs(0, -1))
    {
        patients += dfs(type, -1);
    }
    return patients;
}