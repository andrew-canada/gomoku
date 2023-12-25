#include <bits/stdc++.h>
using namespace std;

int grid[1005][1005];
int vis[1005][1005];
vector<pair<int, int>> patient;
int Hdir[4] = {-1, 1, 0, 0};
int Vdir[4] = {0, 0, -1, 1};

int main()
{
    freopen("covidContainment.in", "r", stdin);
    int t, n, m, q, k;
    int r, c;
    scanf("%d", &t);
    while (t--)
    {
        patient.clear();
        memset(vis, 0, sizeof(vis));
        scanf("%d%d%d%d", &n, &m, &q, &k);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &grid[i][j]);
            }
        }
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", &r, &c);
            grid[r][c] = 2;
            patient.push_back({r, c});
        }
        int num = 0;
        pair<int, int> cur;
        queue<pair<int, int>> q;
        for (pair<int, int> p : patient)
        {
            int curIsl = 0;
            if (vis[p.first][p.second])
            {
                continue;
            }
            q.push(p);
            while (!q.empty())
            {
                cur = q.front();
                q.pop();
                if (vis[cur.first][cur.second])
                {
                    continue;
                }
                vis[cur.first][cur.second] = true;
                if (grid[cur.first][cur.second] == 0)
                {
                    continue;
                }
                if (grid[cur.first][cur.second] == 2)
                {
                    curIsl++;
                }
                for (int i = 0; i < 4; i++)
                {
                    int newR = cur.first + Hdir[i], newC = cur.second + Vdir[i];
                    if (newR >= 0 && newR < m && newC >= 0 && newC < n)
                    {
                        q.push({newR, newC});
                    }
                }
            }
            if (curIsl > k)
            {
                num++;
            }
        }
        printf("%d\n", num);
    }
    return 0;
}