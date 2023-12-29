#include <bits/stdc++.h>
using namespace std;

bool vis[1005];
int nodes;

void dfs(int cur, vector<int> *adjL)
{
    vis[cur] = true;
    printf("%d\n", cur);
    for (int i : adjL[cur])
    {
        if (!vis[i])
        {
            dfs(i, adjL);
        }
    }
    nodes++;
}

void topSort(int n, vector<int> *adjL)
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adjL);
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
        nodes = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            adjL[y].push_back(x);
        }
        topSort(n, adjL);
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