#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
int d[mxN + 1];
int ans;

void dfs(int n = 1, int par = -1)
{
    for (int i : adjL[n])
    {
        if (i == par)
        {
            continue;
        }
        dfs(i, n);
        ans = max(ans, d[n] + d[i] + 1);
        d[n] = max(d[n], d[i] + 1);
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
    dfs();
    cout << ans;
}