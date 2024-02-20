/*
shortest path between all pairs of nodes
1. initialize 2d distance array with given edges (a to b is cost c)
2. try all intermediate nodes from a to b to find shortest path
*/

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 10;

int dp[mxN + 1][mxN + 1];

int main()
{
    memset(dp, INF, sizeof(dp));
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0, u, v, c; i < m; i++)
    {
        cin >> u >> v >> c;
        dp[u][v] = min(dp[u][v], c);
        dp[v][u] = min(dp[v][c], c);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 0, u, v; i < q; i++)
    {
        cin >> u >> v;
        cout << (dp[u][v] >= INF ? -1 : dp[u][v]) << '\n';
    }
}

/*
4 4 4
1 2 3
2 3 4
1 3 5
1 2 2
1 2
1 4
3 1
2 3
*/