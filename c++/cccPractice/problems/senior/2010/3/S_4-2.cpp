#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e3;

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
vector<edge> el;
int vertex[10];
vector<int> adjL[mxN + 1][mxN + 1];

int main()
{
    // m pens from 0 to n-1
    // mth node is the outside
    int m, vt, c;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> vt;
        for (int j = 0; j < vt; j++)
        {
            cin >> vertex[j];
        }
        vertex[vt] = vertex[0];
        for (int j = 0; j < vt; j++)
        {
            cin >> c;
            int u = min(vertex[j], vertex[j + 1]), v = max(vertex[j], vertex[j + 1]);
            if (adjL[u][v].empty())
            {
                adjL[u][v].pb(c);
            }
            adjL[u][v].pb(i);
        }
    }
    for (int i = 1; i <= mxN; i++)
    {
        for (int j = 1; j <= mxN; j++)
        {
            // edge might not exist
            const vector<int> &v = adjL[i][j];
            // connects to outside
            if (v.size() == 2)
            {
                el.pb({v[1], m, v[0]});
            }
            // internal edge
            if (v.size() == 3)
            {
                el.pb({v[1], v[2], v[0]});
            }
        }
    }
    sort(el.begin(), el.end());
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i <= mxN; i++)
    {
        ufds.par[i] = i;
    }
    int ne = 0;
    for (const edge &e : el)
    {
        if (ufds.isSameSet(e.u, e.v) || e.v == m)
        {
            continue;
        }
        ne++;
        ans1 += e.c;
        ufds.unionSet(e.u, e.v);
        if (ne == m - 1)
        {
            break;
        }
    }

    for (int i = 0; i <= mxN; i++)
    {
        ufds.par[i] = i;
    }
    ne = 0;
    for (const edge &e : el)
    {
        if (ufds.isSameSet(e.u, e.v))
        {
            continue;
        }
        ne++;
        ans2 += e.c;
        ufds.unionSet(e.u, e.v);
        if (ne == m)
        {
            break;
        }
    }
    cout << min(ans1, ans2);
}

/*
4
3 1 2 3 7 4 6
4 1 2 4 5 7 7 2 6
4 4 7 6 5 4 8 9 2
5 3 2 4 7 8 4 7 4 7 7
*/