#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 1e5;

vector<int> adjL[mxN + 1], ans;
bool vis[mxN + 1], act[mxN + 1];

void dfs(int a)
{
    vis[a] = true;
    act[a] = true;
    for (int b : adjL[a])
    {
        if (act[b])
        {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        else
        {
            if (!vis[b])
            {
                dfs(b);
            }
        }
    }
    act[a] = false;
    ans.pb(a);
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adjL[a].pb(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans)
    {
        cout << i << " ";
    }
}
