#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e5;

vector<int> adjL[mxN + 1];
int ans[mxN + 1];
int d[mxN + 1];

void dfs(int cur = 1, int par = -1)
{
    for (int i : adjL[cur])
    {
        if (i == par)
        {
            continue;
        }
        dfs(i, cur);
        d[cur] = max(d[cur], d[i] + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjL[a].pb(b), adjL[b].pb(a);
    }
    dfs();
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}