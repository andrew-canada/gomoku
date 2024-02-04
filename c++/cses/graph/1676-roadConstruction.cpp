#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5, mxM = 2e5, M = 1e9 + 7;

struct UFDS
{
    int par[mxN + 1];
    vector<int> size = vector<int>(mxN + 1, 1);
    int mxC, nc;
    void init(int a, int b)
    {
        mxC = a, nc = b;
    }
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
        mxC = max({mxC, size[pu], size[pv]});
        --nc;
    }
};

array<int, 2> el[mxM + 1];
UFDS ufds;

int main()
{
    int n, m;
    cin >> n >> m;
    ufds.init(1, n);
    for (int i = 1; i <= n; i++)
    {
        ufds.par[i] = i;
    }
    int u, v;
    while (m--)
    {
        cin >> u >> v;
        ufds.unionSet(u, v);
        cout << ufds.nc << " " << ufds.mxC << '\n';
    }
}