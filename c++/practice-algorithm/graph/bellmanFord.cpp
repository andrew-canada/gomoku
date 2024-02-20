/*
shortest path in graph with negative edge weights
1. build graph with edge list (node1, node2, cost)
2. traverse graph with edge list and relax edges to calculate distances
3. traverse again to check for negative cycles
*/

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;
typedef array<int, 3> ar;

const int mxN = 10;

int n, m, dist[mxN + 1];
vector<ar> el;

void bellmanFord()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (const ar &a : el)
        {
            if (dist[a[1]] == INF)
            {
                continue;
            }
            dist[a[2]] = min(dist[a[2]], dist[a[1]] + a[0]);
            dist[a[2]] = max(dist[a[2]], -INF);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (const ar &a : el)
        {
            if (dist[a[1]] == INF)
            {
                continue;
            }
            dist[a[2]] = max(dist[a[2]], -INF);
            if (dist[a[1]] + a[0] < dist[a[2]])
            {
                dist[a[2]] = -INF;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    bool cycle = false;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v >> c;
        el.pb({c, u, v});
        cycle = true;
    }
    memset(dist, INF, sizeof(dist));
    dist[1] = 0;
    bellmanFord();
    if (dist[n] == -INF || (cycle && n == 1))
    {
        cout << -1;
    }
    else
    {
        cout << dist[n];
    }
}

/*
4 4
1 2 3
1 4 10
2 3 4
3 4 -6
*/