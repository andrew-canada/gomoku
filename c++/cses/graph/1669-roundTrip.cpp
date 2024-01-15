#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e5;

vector<int> adjL[mxN + 1];
bool vis[mxN + 1];
int p[mxN + 1];

void dfs(int cur, int par = -1)
{
    p[cur] = par;
    vis[cur] = true;
    for (int i : adjL[cur])
    {
        if (i == par)
        {
            continue;
        }
        if (vis[i])
        {
            int cur1 = cur;
            vector<int> ans;
            while (cur ^ i)
            {
                ans.pb(cur);
                cur = p[cur];
            }
            ans.pb(i);
            ans.pb(cur1);
            cout << ans.size() << '\n';
            for (int j : ans)
            {
                cout << j << " ";
            }
            exit(0);
        }
        else
        {
            dfs(i, cur);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjL[a].pb(b), adjL[b].pb(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE\n";
}