#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int mxN = 1e5;
const ll INF = 1e18, NINF = -1e18;

int n, m;

struct edge
{
    ll u, v, c;
    bool operator<(const edge &e)
    {
        return u == e.u ? c < e.c : u < e.u;
    }
};

vector<array<ll, 2>> adjL1[mxN + 1], adjL2[mxN + 1];
ll dist1[mxN + 1], dist2[mxN + 1];
edge el[2 * mxN + 1];

void dijk(vector<array<ll, 2>> *adjL, ll *dist, int start)
{
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    // dist, tar
    pq.push({0, start});
    dist[start] = 0;
    array<ll, 2> cur;
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (cur[0] > dist[cur[1]])
        {
            continue;
        }
        for (array<ll, 2> arr : adjL[cur[1]])
        {
            ll d2 = cur[0] + arr[0];
            if (d2 < dist[arr[1]])
            {
                pq.push({d2, arr[1]});
                dist[arr[1]] = d2;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    ll u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        el[i] = {u, v, c};
    }
    sort(el, el + m);
    for (edge &e : el)
    {
        adjL1[e.u].pb({e.c, e.v}), adjL2[e.v].pb({e.c, e.u});
    }
    for (int i = 1; i <= n; i++)
    {
        dist1[i] = dist2[i] = INF;
    }
    dijk(adjL1, dist1, 1);
    dijk(adjL2, dist2, n);
    ll ans = INF;
    for (int i = 0; i < m; i++)
    {
        edge &e = el[i];
        ans = min(ans, dist1[e.u] + dist2[e.v] + e.c / 2);
    }
    cout << ans;
}