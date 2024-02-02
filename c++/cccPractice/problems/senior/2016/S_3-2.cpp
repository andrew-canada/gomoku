#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 1e5;

int diam, start;
bool pho[mxN + 1];
vector<int> adjL[mxN + 1];

void dfs(int cur, int par, int d)
{
    if (d > diam)
    {
        diam = d;
        start = cur;
    }
    for (int v : adjL[cur])
    {
        if (v != par && pho[v])
        {
            dfs(v, cur, d + 1);
        }
    }
}

void update(int cur, int par)
{
    for (int v : adjL[cur])
    {
        if (v != par)
        {
            update(v, cur);
            if (pho[v])
            {
                pho[cur] = true;
            }
        }
    }
}

int main()
{
    int n, m, x, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        pho[x] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        adjL[u].pb(v);
        adjL[v].pb(u);
    }
    update(x, -1);
    dfs(x, -1, 0);
    dfs(start, -1, 0);
    int np = 0;
    for (int i = 0; i < n; i++)
    {
        if (pho[i])
        {
            np++;
        }
    }
    cout << 2 * (np - 1) - diam;
}