// find the maximum number of nodes visited in cartesian plane
// start at (0, 0)
// nodes can be revisited
// each edge must be shorter than the previous

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

struct edge
{
    int d, x, y;
    bool operator<(const edge &e)
    {
        return d < e.d;
    }
};

int n;
edge edges[2001005];
int coords[2005][2];
int ct[2005], pt[2005];
int dist[2005];

int main()
{
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d%d", &coords[i][0], &coords[i][1]);
    }
    int idx = 0;
    REP(i, 0, n)
    {
        REP(j, i + 1, n)
        {
            edges[idx] = {(coords[i][0] - coords[j][0]) * (coords[i][0] - coords[j][0]) + (coords[i][1] - coords[j][1]) * (coords[i][1] - coords[j][1]), i, j};
            idx++;
        }
    }
    sort(edges, edges + idx);
    REP(i, 0, n * (n + 1) / 2 - 1)
    {
        const edge &e = edges[i];
        if (e.d > dist[e.x])
        {
            dist[e.x] = e.d;
            pt[e.x] = ct[e.x];
        }
        if (e.d > dist[e.y])
        {
            dist[e.y] = e.d;
            pt[e.y] = ct[e.y];
        }
        if (e.x == 0)
        {
            ct[0] = max(ct[0], pt[e.y] + 1);
        }
        else
        {
            ct[e.x] = max(ct[e.x], pt[e.y] + 1);
            ct[e.y] = max(ct[e.y], pt[e.x] + 1);
        }
    }
    printf("%d", ct[0]);
}