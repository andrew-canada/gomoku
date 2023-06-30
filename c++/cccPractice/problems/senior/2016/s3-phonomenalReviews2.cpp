#include <stdio.h>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, m;
vector<int> adjL[100005];
bool isPho[100005];
bool vis[100005];
bool induced[100005];
int d;
int start;

void markInducedNodes(int node, int diameter);

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

    markInducedNodes(0, 0);
    markInducedNodes(start, 0);
    int numPho = 0;
    for (bool b : induced)
    {
        if (b)
        {
            numPho++;
        }
    }
    printf("%d", 2 * (numPho - 1) - d);
}

void markInducedNodes(int node, int diameter)
{
    if (isPho[node])
    {
        induced[node] = true;
        if (diameter > d)
        {
            start = node;
            d = diameter;
        }
    }
    REP(i, 0, adjL[node].size())
    {
        int cur = adjL[node][i];
        if (!vis[cur])
        {
            vis[cur] = true;
            markInducedNodes(cur, diameter + 1);
            if (induced[cur])
            {
                induced[node] = true;
            }
        }
    }
}