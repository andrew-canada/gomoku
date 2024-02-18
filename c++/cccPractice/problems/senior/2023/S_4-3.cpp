#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;
typedef array<ll, 2> all;

const int mxN = 2e3, mxK = 10;

struct edge
{
    int u, v, l, c;
    bool operator<(const edge &e)
    {
        return l == e.l ? c < e.c : l < e.l;
    }
};

vector<edge> el;
ll len[mxN + 1];
vector<all> adjL[mxN + 1];

ll dijk(int u, int v)
{
    priority_queue<all, vector<all>, greater<all>> pq;
    all cur;
    // len, node
    pq.push({0, u});
    memset(len, INF, sizeof(len));
    while (pq.size())
    {
        cur = pq.top();
        pq.pop();
        if (cur[0] > len[cur[1]])
        {
            continue;
        }
        for (const all &a : adjL[cur[1]])
        {
            ll dist = cur[0] + a[0];
            if (dist < len[a[1]])
            {
                len[a[1]] = dist;
                pq.push({dist, a[1]});
            }
        }
    }
    return len[v];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v, l, c; i < m; i++)
    {
        cin >> u >> v >> l >> c;
        el.pb({u, v, l, c});
    }
    sort(el.begin(), el.end());
    ll ans = 0;
    for (const edge &e : el)
    {
        if (e.l < dijk(e.u, e.v))
        {
            ans += e.c;
            adjL[e.u].pb({e.l, e.v});
            adjL[e.v].pb({e.l, e.u});
        }
    }
    cout << ans;
}