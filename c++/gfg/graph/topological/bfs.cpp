#include <bits/stdc++.h>

using namespace std;

vector<int> adjL[100] = {{}, {2, 3}, {}, {2}};
int vis[100];
int inDeg[100];

vector<int> bfs(int n);

int main()
{
    int n = 3;
    vector<int> ord = bfs(n);
    for (int i : ord)
    {
        printf("%d ", i);
    }
}

vector<int> bfs(int n)
{
    vector<int> ord;
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
        vis[cur] = true;
        ord.push_back(cur);
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
    return ord;
}