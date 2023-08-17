#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

typedef tuple<int, int, int> iii;

struct Path
{
    int time, thick, node;
};

struct comp
{
    bool operator()(Path const &p1, Path const &p2)
    {
        return p1.time == p2.time ? p1.thick < p2.thick : p1.time > p2.time;
    }
};

int k, n, m;
int n1, n2;
int dist[2005][2005];
bool vis[2005];
vector<Path> adjL[2005];
priority_queue<Path, vector<Path>, comp> pq;

int main()
{
    memset(dist, 2, sizeof(dist));
    scanf("%d%d%d", &k, &n, &m);
    for (int i = 0; i < m; i++)
    {
        int s, e, t, h;
        scanf("%d%d%d%d", &s, &e, &t, &h);
        adjL[s].push_back({t, h, e});
        adjL[e].push_back({t, h, s});
    }
    scanf("%d%d", &n1, &n2);
    pq.push({0, k, n1});
    int dmg, time;
    while (!pq.empty())
    {
        Path cur = pq.top();
        pq.pop();
        if (cur.time > dist[cur.node][cur.thick])
        {
            continue;
        }
        if (cur.node == n2)
        {
            printf("%d", cur.time);
            return 0;
        }
        for (const Path &p : adjL[cur.node])
        {
            if (p.thick < cur.thick)
            {
                dmg = cur.thick - p.thick;
                time = p.time + cur.time;
                dist[p.node][dmg] = time;
                pq.push({time, dmg, p.node});
            }
        }
    }
    printf("-1");
}