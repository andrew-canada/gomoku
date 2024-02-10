#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 15, mxM = 2e5, M = 1e9 + 7;

int n, eu[1 << mxN], ev[1 << mxN];
vector<int> adjL[1 << mxN], ans;
bool vis[1 << mxN];

void dfs(int u = 0)
{
    while (!adjL[u].empty())
    {
        int e = adjL[u].back();
        adjL[u].pop_back();
        if (vis[e])
        {
            continue;
        }
        vis[e] = true;
        dfs(u ^ eu[e] ^ ev[e]);
        ans.pb(e);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        eu[i] = i / 2;
        ev[i] = i & ((1 << (n - 1)) - 1);
        adjL[eu[i]].pb(i);
    }
    dfs();
    for (int i : ans)
    {
        cout << i % 2;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << 0;
    }
}