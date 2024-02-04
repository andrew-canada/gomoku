#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5, mxM = 2e5, M = 1e9 + 7;

struct edge
{
    int u, v, c;
    bool operator<(const edge &e)
    {
        return c < e.c;
    }
};

struct UFDS
{
    int par[mxN + 1];
    vector<int> size = vector<int>(mxN + 1, 1);
    int findSet(int u)
    {
        return u == par[u] ? u : par[u] = findSet(par[u]);
    }
    bool isSameSet(int u, int v)
    {
        return findSet(u) == findSet(v);
    }
    void unionSet(int u, int v)
    {
        int pu = findSet(u), pv = findSet(v);
        if (pu == pv)
        {
            return;
        }
        if (size[pu] >= size[pv])
        {
            size[pu] += size[pv];
            par[pv] = pu;
        }
        else
        {
            size[pv] += size[pu];
            par[pu] = pv;
        }
    }
};

edge el[mxM + 1];
UFDS ufds;

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        el[i] = {u, v, c};
    }
    sort(el, el + m);
    for (int i = 1; i <= n; i++)
    {
        ufds.par[i] = i;
    }
    ll ans = 0;
    int ne = 0;
    for (edge e : el)
    {
        if (ne == n - 1)
        {
            cout << ans;
            return 0;
        }
        if (ufds.isSameSet(e.u, e.v))
        {
            continue;
        }
        ufds.unionSet(e.u, e.v);
        ne++;
        ans += e.c;
    }
    cout << "IMPOSSIBLE";
}