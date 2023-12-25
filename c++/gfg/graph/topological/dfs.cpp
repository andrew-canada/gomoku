#include <bits/stdc++.h>

using namespace std;

vector<int> adjL[100] = {{}, {2, 3}, {}, {2}};
int vis[100];
vector<int> ord;
int n = 3;

void dfs(int cur);
void topOrdDfs();

int main()
{
    topOrdDfs();
    for (int i : ord)
    {
        printf("%d ", i);
    }
}

void dfs(int cur)
{
    vis[cur] = true;
    for (int i : adjL[cur])
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    ord.push_back(cur);
}

void topOrdDfs()
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    reverse(ord.begin(), ord.end());
}