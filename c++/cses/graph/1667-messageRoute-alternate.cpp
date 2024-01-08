#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e5;

vector<int> adjL[mxN + 1];
bool vis[mxN + 1];
int par[mxN + 1];

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
    queue<int> q;
    q.push(1);
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == n)
        {
            break;
        }
        for (int i : adjL[cur])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = true;
                par[i] = cur;
            }
        }
    }

    vector<int> path;
    if (vis[n])
    {
        int nd = n;
        path.pb(nd);
        while (nd != 1)
        {
            path.pb(par[nd]);
            nd = par[nd];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for (int i : path)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}