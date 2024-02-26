/*
lowest common ancestor
1. build tree with adjL
2. dfs with binary lifting to find ancestors and node depth
3. find ancestor using binary lifting (similar to binary search)
    a) find ancestor of deeper node to make one node equal depth to the other
    b) binary lift: if i-th ancestor is equal, no change (like binary sort taking lower)
        if i-th ancestor is not equal, take as ancestor (like binary sort taking higher)
    c) final answer is parent of ancestor found in b)
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5, logN = 18;

int anc[mxN + 1][logN + 1], d[mxN + 1];
vector<int> adjL[mxN + 1];

void dfs(int u = 1, int p = -1)
{
    anc[u][0] = p;
    for (int i = 1; i <= logN; i++)
    {
        anc[u][i] = ~anc[u][i - 1] ? anc[anc[u][i - 1]][i - 1] : -1;
    }
    for (int v : adjL[u])
    {
        if (v == p)
        {
            continue;
        }
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    // make sure u is deeper node
    if (d[v] > d[u])
    {
        swap(u, v);
    }
    for (int i = logN; ~i; i--)
    {
        if (d[u] - (1 << i) >= d[v])
        {
            u = anc[u][i];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int i = logN; ~i; i--)
    {
        if (anc[u][i] ^ anc[v][i])
        {
            u = anc[u][i], v = anc[v][i];
        }
    }
    return anc[u][0];
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 2, p; i <= n; i++)
    {
        cin >> p;
        adjL[p].pb(i);
    }
    dfs();
    int u, v;
    while (q--)
    {
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}