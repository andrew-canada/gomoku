#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
int ans, nd;

void dfs(int n, int par, int d)
{
    if (d > ans)
    {
        ans = d;
        nd = n;
    }
    for (int i : adjL[n])
    {
        if (i != par)
        {
            dfs(i, n, d + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adjL[a].pb(b);
        adjL[b].pb(a);
    }
    dfs(b, -1, 0);
    dfs(nd, -1, 0);
    cout << ans;
}