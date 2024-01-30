#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef unsigned long long ull;
typedef vector<vector<ull>> mat;

const int mxN = 100, M = 1e9 + 7;

mat mult(mat &a, mat &b)
{
    mat res(a.size(), vector<ull>(b[0].size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            for (int k = 0; k < b[0].size(); k++)
            {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % M) % M;
            }
        }
    }
    return res;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    mat adj(n + 1, vector<ull>(n + 1, 0));
    mat ans(n + 1, vector<ull>(n + 1, 0));
    while (m--)
    {
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a][b]++;
    }
    for (int i = 0; i < n; i++)
    {
        ans[i][i] = 1;
    }
    while (k)
    {
        if (k & 1)
        {
            ans = mult(ans, adj);
        }
        adj = mult(adj, adj);
        k >>= 1;
    }
    cout << ans[0][n - 1];
}