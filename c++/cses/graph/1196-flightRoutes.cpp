#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 1e5;

int n, m, k;
vector<array<ll, 2>> adjL[mxN + 1];
vector<ll> dist[mxN + 1];

void dijk()
{
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    // dist, node
    pq.push({0, 1});
    array<ll, 2> cur;
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (dist[cur[1]].size() >= k)
        {
            continue;
        }
        dist[cur[1]].pb({cur[0]});
        for (array<ll, 2> ar : adjL[cur[1]])
        {
            pq.push({cur[0] + ar[0], ar[1]});
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    ll u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        adjL[u].pb({c, v});
    }
    dijk();
    for (int i = 0; i < k; i++)
    {
        cout << dist[n][i] << " ";
    }
}