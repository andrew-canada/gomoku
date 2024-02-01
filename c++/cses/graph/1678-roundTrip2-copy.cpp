#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 1e5;

vector<int> adjL[mxN + 1];
bool vis[mxN + 1], act[mxN + 1];
int par[mxN + 1];

void dfs(int a)
{
    vis[a] = true, act[a] = true;
    for (int b : adjL[a])
    {
        if (act[b])
        {
            vector<int> ans = {a};
            while (a ^ b)
            {
                a = par[a];
                ans.pb(a);
            }
            ans.pb(ans[0]);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            for (int i : ans)
            {
                cout << i << " ";
            }
            exit(0);
        }
        else
        {
            if (!vis[b])
            {
                par[b] = a;
                dfs(b);
            }
        }
    }
    act[a] = false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v, u, v;
        adjL[u].pb(v);
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