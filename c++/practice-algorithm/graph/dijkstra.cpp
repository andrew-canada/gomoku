#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

const int mxN = 100;

/*
dijkstra = find single source shortest path on graph with positive edge weights
1. Build graph
    a) adjacency list storing: cost, node 2
2. Traverse graph using bfs on adjacency list
    a) use priority queue to store and sort edges
    b) update distance array
*/

vector<array<int, 2>> adjL[mxN + 1];
int dist[mxN + 1];

void dijk()
{
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    dist[1] = 0;
    // cost, node
    pq.push({0, 1});
    array<int, 2> cur;
    while (pq.size())
    {
        cur = pq.top();
        pq.pop();
        if (cur[0] > dist[cur[1]])
        {
            continue;
        }
        for (array<int, 2> ar : adjL[cur[1]])
        {
            int cost = cur[0] + ar[0];
            if (cost < dist[ar[1]])
            {
                pq.push({cost, ar[1]});
                dist[ar[1]] = cost;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v >> c;
        // cost, node 2
        adjL[u].pb({c, v});
    }
    memset(dist, INF, sizeof(dist));
    dijk();
    for (int i = 1; i <= n; i++)
    {
        cout << i << ":" << dist[i] << " ";
    }
}

/*
6 7
1 2 2
1 3 4
2 4 1
2 5 1
3 5 7
4 6 10
5 6 1
*/