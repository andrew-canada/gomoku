#include <bits/stdc++.h>
using namespace std;

vector<int> dc;
int vis[10005];

int dfs(int cur, vector<int> *adjL, int nc)
{
    printf("cur: %d\n", cur);
    for (int nd : adjL[cur])
    {
        if (nd == 1)
        {
            printf("ret: %d\n", nc);
            printf("vector begin\n");
            for (int i : dc)
            {
                printf("%d ", i);
            }
            printf("\nvector end\n");
            return nc;
        }
        nc++;
        dc.push_back(nd);
        vis[nd] = true;
        printf("num: %d\n next: %d\n", nc, nd);
        dfs(nd, adjL, nc);
    }
    printf("pop: %d\n", dc.back());
    dc.pop_back();
    nc -= 2;
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
        printf("%d\n", dfs(1, adjL, 1));
        for (int c : dc)
        {
            printf("%d ", c);
        }
        printf("\n");
    }
    return 0;
}