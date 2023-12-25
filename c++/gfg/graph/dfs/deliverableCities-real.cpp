#include <bits/stdc++.h>
using namespace std;

bool vis[10005];
bool visR[10005];

void dfs(int cur, vector<int> *al, bool *v)
{
    v[cur] = true;
    for (int c : al[cur])
    {
        if (!v[c])
        {
            dfs(c, al, v);
        }
    }
}

int main()
{
    freopen("deliverableCities.in", "r", stdin);
    freopen("deliverableCities.out", "w", stdout);
    int t;
    int n, m, x, y;
    scanf("%d", &t);
    while (t--)
    {
        vector<int> adjL[10005];
        vector<int> adjLR[10005];
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &x, &y);
            adjL[x].push_back(y);
            adjLR[y].push_back(x);
        }
        memset(vis, 0, sizeof(vis));
        memset(visR, 0, sizeof(visR));
        dfs(1, adjL, vis);
        dfs(1, adjLR, visR);
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] && visR[i])
            {
                ans.push_back(i);
            }
        }
        printf("%d\n", ans.size());
        for (int c : ans)
        {
            printf("%d ", c);
        }
        printf("\n");
    }
    return 0;
}