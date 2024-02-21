#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef array<int, 3> ar;

const int mxN = 2e5;

vector<ar> el;
map<array<int, 2>, int> mp;
char col[mxN + 1];
char colNode[mxN + 1];

struct UFDS
{
    int par[mxN + 1];
    vector<int> sz = vector<int>(mxN + 1, 1);
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
        if (colNode[u] != colNode[v])
        {
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
            col[mp[{u, v}]] = 'R';
            colNode[u] = 'R', colNode[v] = 'R';
        }
        else
        {
            if (sz[pu] >= sz[pv])
            {
                sz[pu] += sz[pv];
                par[pv] = pu;
                col[mp[{u, v}]] = 'B';
                colNode[v] = 'B';
            }
            else
            {
                sz[pv] += sz[pu];
                par[pu] = pv;
                col[mp[{u, v}]] = 'B';
                colNode[u] = 'B';
            }
        }
    }
};

UFDS ufds;

int main()
{
    memset(col, 'G', sizeof(col));
    memset(colNode, 'G', sizeof(colNode));
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v;
        c = 1;
        el.pb({c, u, v});
        mp[{u, v}] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        ufds.par[i] = i;
    }
    int ne = 0, ans = 0;
    for (const ar &a : el)
    {
        if (ufds.isSameSet(a[1], a[2]))
        {
            continue;
        }
        ne++;
        ufds.unionSet(a[1], a[2]);
    }
    for (int i = 0; i < m; i++)
    {
        if (col[i] != 'G')
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

/*
5 7
1 2
2 4
5 2
4 5
4 3
1 3
1 4
*/