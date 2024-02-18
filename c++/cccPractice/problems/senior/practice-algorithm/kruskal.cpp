/*
minimum spanning tree
1. build graph using edge list: store node1, node2
2. create minimum spanning tree using ufds
    a) union nodes until all nodes are connected
    b) functions: findSet, isSameSet, unionSet
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

const int mxN = 100, mxE = 1e3;

struct UFDS
{
    int par[mxN + 1];
    vector<int> sz = vector<int>(mxN, 1);
    int findSet(int u)
    {
        return u == par[u] ? u : findSet(par[u]);
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
        if (sz[pu] >= sz[pv])
        {
            sz[pu] += sz[pv];
            par[pv] = pu;
        }
        else
        {
            sz[pv] += sz[pu];
            par[pu] = pv;
        }
    }
};

UFDS ufds;
array<int, 3> el[mxN + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v >> c;
        // cost, u, v
        el[i] = {c, u, v};
    }
    sort(el, el + m);
    int ne = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ufds.par[i] = i;
    }
    for (const array<int, 3> &ar : el)
    {
        if (ne == n - 1)
        {
            cout << ans;
            return 0;
        }
        if (ufds.isSameSet(ar[1], ar[2]))
        {
            continue;
        }
        ne++;
        ans += ar[0];
        ufds.unionSet(ar[1], ar[2]);
    }
}

/*
5 6
1 2 1
1 4 2
1 3 2
2 4 3
2 5 5
3 5 4
*/