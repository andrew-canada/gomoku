#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e5, mxM = 2e5;

struct edge
{
    int u, v, c, n;
    bool operator<(const edge &e)
    {
        return c == e.c ? n < e.n : c < e.c;
    }
};

struct UFDS
{
    int par[mxN + 1];
    vector<int> size = vector<int>(mxN + 1, 1);
    int findSet(int a)
    {
        return a == par[a] ? a : par[a] = findSet(par[a]);
    }
    bool isSameSet(int a, int b)
    {
        return findSet(a) == findSet(b);
    }
    void unionSet(int a, int b)
    {
        int p1 = findSet(a), p2 = findSet(b);
        if (p1 == p2)
        {
            return;
        }
        if (size[p1] >= size[p2])
        {
            size[p1] += size[p2];
            par[p2] = p1;
        }
        else
        {
            size[p2] += size[p1];
            par[p1] = p2;
        }
    }
};

edge el[mxM + 1];
UFDS ufds;

int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++)
    {
        cin >> el[i].u >> el[i].v >> el[i].c;
        el[i].n = i;
    }
    sort(el, el + m);

    for (int i = 1; i <= n; i++)
    {
        ufds.par[i] = i;
    }
    int ans = 0, ne = 0, mxC = 0;
    for (int i = 0; i < m; i++)
    {
        edge e = el[i];
        if (ne == n - 1)
        {
            break;
        }
        if (ufds.isSameSet(e.u, e.v))
        {
            continue;
        }
        ne++;
        ufds.unionSet(e.u, e.v);
        if (e.n >= n - 1)
        {
            ans++;
        }
        mxC = e.c;
    }

    for (int i = 1; i <= n; i++)
    {
        ufds.par[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        edge e = el[i];
        if (ufds.isSameSet(e.u, e.v))
        {
            continue;
        }
        if (e.c < mxC || (e.n < n - 1 && e.c == mxC))
        {
            ufds.unionSet(e.u, e.v);
        }
        else if (e.n < n - 1 && e.c < d)
        {
            ans--;
            break;
        }
    }
    cout << ans;
}