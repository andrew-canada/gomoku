#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e5;

vector<int> adjL[mxN + 1];
bool vis[mxN + 1];
int team[mxN + 1];

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
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            team[i] = 1;
            queue<array<int, 2>> q;
            array<int, 2> cur;
            q.push({i, 0});
            while (!q.empty())
            {
                cur = q.front();
                q.pop();
                for (int j : adjL[cur[0]])
                {
                    if (!vis[j])
                    {
                        vis[j] = true;
                        q.push({j, !cur[1]});
                        team[j] = (!cur[1]) + 1;
                        if (team[j])
                        {
                            if (((!cur[1]) + 1 == team[j]))
                            {
                                cout << "IMPOSSIBLE";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << team[i] << " ";
    }
}