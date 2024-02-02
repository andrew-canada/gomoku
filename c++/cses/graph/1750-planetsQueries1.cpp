#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 2e5, mxX = 1e6, M = 1e9 + 7;

int tar[30][mxN + 1];

int main()
{
    // freopen("1750.in", "r", stdin);
    // freopen("1750.out", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n, q, x, k;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> tar[0][i], --tar[0][i];
    }
    for (int j = 1; j < 30; j++)
    {
        for (int i = 0; i < n; i++)
        {
            tar[j][i] = tar[j - 1][tar[j - 1][i]];
        }
    }
    while (q--)
    {
        cin >> x >> k, --x;
        for (int i = 0; i < 30; i++)
        {
            if ((k >> i) & 1)
            {
                x = tar[i][x];
            }
        }
        cout << x + 1 << '\n';
    }
}