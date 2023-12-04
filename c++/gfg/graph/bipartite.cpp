#include <bits/stdc++.h>

using namespace std;

bool bipartite(vector<vector<int>> adjL, int n);

int c[20];

int main()
{
    int n1 = 4;
    vector<vector<int>> adjL1 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    printf("%d\n", bipartite(adjL1, n1));

    int n2 = 3;
    vector<vector<int>> adjL2 = {{1, 2}, {0, 2}, {0, 1}};
    printf("%d\n", bipartite(adjL2, n2));
}

bool bipartite(vector<vector<int>> adjL, int n)
{
    memset(c, -1, sizeof(c));
    for (int i = 0; i < n; i++)
    {
        if (c[i] == -1)
        {
            c[i] = 1;
            queue<int> q;
            q.push(i);
            int cur;
            while (!q.empty())
            {
                cur = q.front();
                q.pop();
                for (int nxt : adjL[cur])
                {
                    if (c[cur] == c[nxt])
                    {
                        return false;
                    }
                    if (c[nxt] == -1)
                    {
                        q.push(nxt);
                        c[nxt] = !c[cur];
                    }
                }
            }
        }
    }
    return true;
}