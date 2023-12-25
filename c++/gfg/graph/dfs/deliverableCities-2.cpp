#include <bits/stdc++.h>
using namespace std;

vector<int> dc;
vector<int> ans;
int vis[10005];

void dfs(int cur, vector<int> *adjL)
{
    for (int nd : adjL[cur])
    {
        if (nd == 1)
        {
            ans = dc;
            return;
        }
        dc.push_back(nd);
        vis[nd] = true;
        dfs(nd, adjL);
    }
    dc.pop_back();
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
        scanf("%d%d", &n, &m);
        vector<int> adjL[10005];
        dc.clear();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &x, &y);
            adjL[x].push_back(y);
        }
        dc.push_back(1);
        vis[1] = true;
        dfs(1, adjL);
        printf("%d\n", ans.size());
        for (int c : ans)
        {
            printf("%d ", c);
        }
        printf("\n");
    }
    return 0;
}