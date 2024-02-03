#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxA = 1e6, mxG = 1e5, mxN = 2e3;

struct edge
{
    int v, t, h;
};

struct comp
{
    bool operator()(const edge &e1, const edge &e2)
    {
        return e1.t > e2.t;
    }
};

vector<edge> adjL[mxN + 1];
int hull[mxN + 1];

int main()
{
    int k, n, m;
    cin >> k >> n >> m;
    int a, b, t, h;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> t >> h;
        adjL[a].pb({b, t, h});
        adjL[b].pb({a, t, h});
    }
    int u, v;
    cin >> u >> v;
    priority_queue<edge, vector<edge>, comp> pq;
    edge cur;
    // node, time, hull
    pq.push({u, 0, k});
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (cur.h <= hull[cur.v])
        {
            continue;
        }
        hull[cur.v] = cur.h;
        if (cur.v == v)
        {
            cout << cur.t;
            return 0;
        }
        for (edge e : adjL[cur.v])
        {
            if (cur.h > e.h)
            {
                pq.push({e.v, cur.t + e.t, cur.h - e.h});
            }
        }
    }
    cout << -1;
}

/*
10 4 7
1 2 4 4
1 3 7 2
3 1 8 1
3 2 2 2
4 2 1 6
3 4 1 1
1 4 6 12
1 4
*/