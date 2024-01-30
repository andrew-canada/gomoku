#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 2e18

typedef unsigned long long ull;
typedef vector<vector<ull>> mat;

const int mxN = 100, M = 1e9 + 7;

mat mult(mat &a, mat &b)
{
    mat res(a.size(), vector<ull>(b[0].size(), INF));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            for (int k = 0; k < b[0].size(); k++)
            {
                res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return res;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    mat res(n, vector<ull>(n, INF)), b(n, vector<ull>(n, INF));
    for (int i = 0; i < n; i++)
    {
        res[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        ull u, v, d;
        cin >> u >> v >> d, --u, --v;
        // b[u][v] = d;
        // might be multiple paths between u and v. take the shortest
        b[u][v] = min(d, b[u][v]);
    }
    while (k)
    {
        if (k & 1)
        {
            res = mult(res, b);
        }
        b = mult(b, b);
        k >>= 1;
    }
    if (res[0][n - 1] >= INF)
    {
        cout << -1;
    }
    else
    {
        cout << res[0][n - 1];
    }
}