#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

typedef tuple<int, int, int> iii;

struct Path
{
    int time, node, thick;
};

struct comp
{
    bool operator()(Path const &p1, Path const &p2)
    {
        return p1.time == p2.time ? p1.node < p2.node : p1.time > p2.time;
    }
};

int k, n, m;
int n1, n2;
int hull[2005];
vector<Path> adjL[2005];
priority_queue<Path, vector<Path>, comp> pq;

int main()
{
    memset(hull, -2, sizeof(hull));
    scanf("%d%d%d", &k, &n, &m);
    for (int i = 0; i < m; i++)
    {
        int s, e, t, h;
        scanf("%d%d%d%d", &s, &e, &t, &h);
        adjL[s].push_back({t, e, h});
        adjL[e].push_back({t, s, h});
    }
    scanf("%d%d", &n1, &n2);
    pq.push({0, n1, k});
    while (!pq.empty())
    {
        Path cur = pq.top();
        pq.pop();
        if (cur.thick <= hull[cur.node])
        {
            continue;
        }
        hull[cur.node] = cur.thick;
        if (cur.node == n2)
        {
            printf("%d", cur.time);
            return 0;
        }
        for (const Path &p : adjL[cur.node])
        {
            if (cur.thick > p.thick)
            {
                pq.push({cur.time + p.time, p.node, cur.thick - p.thick});
            }
        }
    }
    printf("-1");
}