#include <bits/stdc++.h>
using namespace std;

bool vis[1005];
int inDeg[1005];
int nodes;

void bfs(int n, vector<int> *adjL)
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
        printf("nodes: %d cur: %d\n", nodes, cur);
        vis[cur] = true;
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
    int t, n, m;
    int x, y;
    scanf("%d", &t);
    while (t--)
    {
        vector<int> adjL[1005];
        memset(vis, 0, sizeof(vis));
        memset(inDeg, 0, sizeof(inDeg));
        nodes = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            adjL[y].push_back(x);
        }
        bfs(n, adjL);
        if (nodes == n)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}