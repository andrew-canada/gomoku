#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int mxN = 2.5e3;
const ll INF = 5e13, NINF = -5e13;

struct edge
{
    ll u, v, c;
};

int n, m;
ll dist[mxN + 1];
edge el[mxN * 2 + 1];

void bellmanFord()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (edge &e : el)
        {
            if (dist[e.u] == INF)
            {
                continue;
            }
            dist[e.v] = min(dist[e.v], dist[e.u] + e.c);
            dist[e.v] = max(dist[e.v], NINF);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (edge &e : el)
        {
            if (dist[e.u] == INF)
            {
                continue;
            }
            dist[e.v] = max(dist[e.v], NINF);
            if (dist[e.u] + e.c < dist[e.v])
            {
                dist[e.v] = NINF;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    ll a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c, --a, --b, c *= -1;
        el[i] = {a, b, c};
    }
    for (int i = 1; i < n; i++)
    {
        dist[i] = INF;
    }
    bellmanFord();
    if (dist[n - 1] == NINF || (n == 1 && el[0].c < 0))
    {
        cout << -1;
    }
    else
    {
        cout << dist[n - 1] * -1;
    }
}