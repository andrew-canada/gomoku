#include <bits/stdc++.h>
using namespace std;

bool vis[100005];
int inDeg[100005];
int ans[100005];

bool bfs(int n, vector<int> *adjL)
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
    int val = 1;
    while (!q.empty())
    {
        if (q.size() != 1)
        {
            return false;
        }
        cur = q.front();
        q.pop();
        vis[cur] = true;
        ans[cur] = val++;
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
    return true;
}

int main()
{
    int t, n, m;
    int x, y;
    scanf("%d", &t);
    while (t--)
    {
        vector<int> adjL[100005];
        memset(vis, 0, sizeof(vis));
        memset(inDeg, 0, sizeof(inDeg));
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &x, &y);
            adjL[x].push_back(y);
        }
        if (bfs(n, adjL))
        {
            printf("Yes\n");
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", ans[i]);
            }
            printf("\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}