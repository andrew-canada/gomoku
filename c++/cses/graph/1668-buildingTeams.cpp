#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e5;

vector<int> adjL[mxN + 1];
int team[mxN + 1];

void dfs(int cur, bool t = 0)
{
    if (~team[cur])
    {
        if (team[cur] ^ t)
        {
            cout << "IMPOSSIBLE";
            exit(0);
        }
        return;
    }
    team[cur] = t;
    for (int i : adjL[cur])
    {
        dfs(i, !t);
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
        adjL[a].pb(b);
        adjL[b].pb(a);
    }
    memset(team, -1, sizeof(team));
    for (int i = 1; i <= n; i++)
    {
        if (team[i] == -1)
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << team[i] + 1 << " ";
    }
}