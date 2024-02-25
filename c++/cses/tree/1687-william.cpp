#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

int anc[mxN][19], d[mxN];
vector<int> adjL[mxN];

void dfs(int u = 0, int p = -1)
{
    anc[u][0] = p;
    for (int i = 1; i < 19; i++)
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

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1, p; i < n; i++)
    {
        cin >> p, --p;
        adjL[p].pb(i);
    }
    dfs();
    int x, k;
    while (q--)
    {
        cin >> x >> k, --x;
        if (d[x] < k)
        {
            cout << "-1\n";
        }
        else
        {
            for (int i = 18; ~i; i--)
            {
                if (k >> i & 1)
                {
                    x = anc[x][i];
                }
            }
            cout << x + 1 << '\n';
        }
    }
}