#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
typedef array<int, 3> ar;

const int mxN = 100, mxE = 1e3;

struct UFDS
{
    int par[mxN + 1];
    vector<int> sz = vector<int>(mxN, 1);
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
vector<ar> el;
int corner[10];
vector<int> adjL[mxE + 1][mxE + 1];

int main()
{
    int m;
    cin >> m;
    for (int i = 0, e; i < m; i++)
    {
        cin >> e;
        for (int j = 0; j < e; j++)
        {
            cin >> corner[j];
        }
        corner[e] = corner[0];
        int cost, u, v;
        for (int j = 0; j < e; j++)
        {
            cin >> cost;
            u = min(corner[j], corner[j + 1]), v = max(corner[j], corner[j + 1]);
            if (adjL[u][v].empty())
            {
                adjL[u][v].pb(cost);
            }
            adjL[u][v].pb(i);
        }
    }

    for (int i = 1; i <= mxE; i++)
    {
        for (int j = 1; j <= mxE; j++)
        {
            vector<int> &cur = adjL[i][j];
            if (cur.size() == 2)
            {
                // cost, u, v
                el.pb({cur[0], cur[1], m});
            }
            else if (cur.size() == 3)
            {
                el.pb({cur[0], cur[1], cur[2]});
            }
        }
    }
    sort(el.begin(), el.end());

    int ne = 0, ans1 = 0, ans2 = 0;
    for (int i = 0; i <= m; i++)
    {
        ufds.par[i] = i;
    }
    for (const ar &a : el)
    {
        if (a[2] == m || ufds.isSameSet(a[1], a[2]))
        {
            continue;
        }
        ne++;
        ans1 += a[0];
        ufds.unionSet(a[1], a[2]);
        if (ne == m - 1)
        {
            break;
        }
    }

    ne = 0;
    for (int i = 0; i <= m; i++)
    {
        ufds.par[i] = i;
    }
    for (const ar &a : el)
    {
        if (ufds.isSameSet(a[1], a[2]))
        {
            continue;
        }
        ne++;
        ans2 += a[0];
        ufds.unionSet(a[1], a[2]);
        if (ne == m)
        {
            break;
        }
    }

    cout << min(ans1, ans2);
}