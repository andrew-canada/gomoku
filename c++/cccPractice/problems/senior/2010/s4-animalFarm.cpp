#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct edge
{
    int w, from, to;
    bool operator<(edge e)
    {
        return w < e.w;
    }
};

int n, e;
vector<int> adjL[1005][1005];
int corner[10];
int par[1005];
vector<edge> edges;
int cost1, cost2;

int findSet(int p);
bool isSameSet(int p1, int p2);
void unionSet(int p1, int p2);

int main()
{
    scanf("%d", &n);
    int w;
    REP(i, 0, n - 1)
    {
        scanf("%d", &e);
        REP(j, 0, e - 1)
        {
            scanf("%d", &corner[j]);
        }
        corner[e] = corner[0];
        REP(j, 0, e - 1)
        {
            scanf("%d", &w);
            int v1 = MIN(corner[j], corner[j + 1]), v2 = MAX(corner[j], corner[j + 1]);
            if (adjL[v1][v2].size() == 0)
            {
                adjL[v1][v2].push_back(w);
            }
            adjL[v1][v2].push_back(i);
        }
    }
    REP(i, 1, 1000)
    {
        REP(j, 1, 1000)
        {
            if (adjL[i][j].size() == 2)
            {
                edges.push_back({adjL[i][j][0], adjL[i][j][1], n});
            }
            else if (adjL[i][j].size() == 3)
            {
                edges.push_back({adjL[i][j][0], adjL[i][j][1], adjL[i][j][2]});
            }
        }
    }

    sort(edges.begin(), edges.end());
    int numE = 0;
    REP(i, 0, 1000)
    {
        par[i] = i;
    }
    for (const edge &curE : edges)
    {
        if (curE.to == n || isSameSet(curE.from, curE.to))
        {
            continue;
        }
        numE++;
        cost1 += curE.w;
        unionSet(curE.from, curE.to);
        if (numE == n - 1)
        {
            break;
        }
    }

    numE = 0;
    REP(i, 0, 1000)
    {
        par[i] = i;
    }
    for (const edge &curE : edges)
    {
        if (isSameSet(curE.from, curE.to))
        {
            continue;
        }
        numE++;
        cost2 += curE.w;
        unionSet(curE.from, curE.to);
        if (numE == n)
        {
            break;
        }
    }
    printf("%d", MIN(cost1, cost2));
}

int findSet(int p)
{
    return (par[p] == p) ? p : (par[p] = findSet(par[p]));
}

bool isSameSet(int p1, int p2)
{
    return findSet(p1) == findSet(p2);
}

void unionSet(int p1, int p2)
{
    if (isSameSet(p1, p2))
    {
        return;
    }
    int par1 = findSet(p1), par2 = findSet(p2);
    par[par1] = par2;
}