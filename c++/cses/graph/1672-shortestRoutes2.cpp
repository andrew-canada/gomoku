#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 500;

ll dp[mxN + 1][mxN + 1];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    ll a, b, c;
    memset(dp, INF, sizeof(dp));
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        --a, --b;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while (q--)
    {
        cin >> a >> b;
        --a, --b;
        cout << (dp[a][b] >= 5e11 ? -1 : dp[a][b]) << '\n';
    }
}