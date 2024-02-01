#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 1e5;

int n, m;
vector<int> adjL[mxN + 1], ans;
bool vis[mxN + 1];
int inDeg[mxN + 1], nodes;

void bfs()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j : adjL[i])
        {
            inDeg[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        nodes++;
        vis[cur] = true;
        ans.pb(cur);
        for (int i : adjL[cur])
        {
            if (!vis[i])
            {
                inDeg[i]--;
                if (inDeg[i] == 0)
                {
                    q.push(i);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adjL[a].push_back(b);
    }
    bfs();
    if (nodes == n)
    {
        for (int i : ans)
        {
            cout << i << " ";
        }
    }
    else
    {
        printf("IMPOSSIBLE");
    }
    return 0;
}