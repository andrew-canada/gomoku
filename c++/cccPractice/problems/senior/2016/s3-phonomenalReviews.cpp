#include <stdio.h>
#include <vector>
#include <numeric>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, m;
vector<int> adjL[100005];
bool isPho[100005];
bool vis[100005];
int dist[100005];
queue<int> path;
int farthest;
int d;

int getFarthestNode(int start);
int getLongestPath(int start);
int calculateDiameter();

void removeNonSubgraphVertices()
{
    queue<int> leaves;

    REP(i, 0, n)
    {
        if (adjL[i].size() == 1 && !isPho[i])
        {
            leaves.push(i);
        }
    }

    while (!leaves.empty())
    {
        int leaf = leaves.front();
        leaves.pop();

        vis[leaf] = true;

        int neighbor = adjL[leaf][0];
        adjL[neighbor].erase(find(adjL[neighbor].begin(), adjL[neighbor].end(), leaf));

        if (adjL[neighbor].size() == 1 && !isPho[neighbor] && !vis[neighbor])
        {
            leaves.push(neighbor);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int ind;
    REP(i, 0, m)
    {
        scanf("%d", &ind);
        isPho[ind] = true;
    }

    int n1, n2;
    REP(i, 0, n - 1)
    {
        scanf("%d%d", &n1, &n2);
        adjL[n1].push_back(n2);
        adjL[n2].push_back(n1);
    }

    d = calculateDiameter();
    int numPho = accumulate(isPho, isPho + n, 0);
    printf("%d", 2 * (numPho - 1) - d);
}

int getFarthestNode(int start)
{
    int farthest = 0;
    vector<int> vis1(n, 0);
    vis1[start] = true;
    queue<int> path1;
    path1.push(start);
    while (!path1.empty())
    {
        int cur = path1.front();
        path1.pop();
        farthest = cur;
        for (int v : adjL[cur])
        {
            if (!vis1[v])
            {
                path1.push(v);
                vis1[v] = true;
                if (isPho[v])
                {
                    isPho[cur] = true;
                }
            }
        }
    }
    return farthest;
}

int getLongestPath(int start)
{
    path.push(start);
    vis[start] = true;

    while (!path.empty())
    {
        int cur = path.front();
        path.pop();
        for (int v : adjL[cur])
        {
            if (!vis[v])
            {
                path.push(v);
                vis[v] = true;
                dist[v] = dist[cur] + 1;
            }
        }
    }
    return dist[max_element(dist, dist + n) - dist];
}

int calculateDiameter()
{
    farthest = getFarthestNode(0);
    farthest = getFarthestNode(farthest);
    return getLongestPath(farthest);
}