#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 2e5, mxX = 1e6, M = 1e9 + 7;

int adjL[mxN + 1];

int dfs(int x, int k)
{
    if (!k || (x == adjL[x]))
    {
        return x;
    }
    return dfs(adjL[x], k - 1);
}

int main()
{
    int n, q, t, x, k;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        adjL[i] = t;
    }
    while (q--)
    {
        cin >> x >> k;
        cout << dfs(x, k) << '\n';
    }
}