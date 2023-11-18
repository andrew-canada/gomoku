#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

struct route
{
    int n2, t, h;
};

struct comp
{
    bool operator()(const route &r1, const route &r2)
    {
        return r1.t == r2.t ? r1.n2 < r2.n2 : r1.t > r2.t;
    }
};

int k, n, m;
vector<route> adjL[2005];
int hull[2005];
priority_queue<route, vector<route>, comp> pq;
int n1, n2;

int main()
{
    scanf("%d%d%d", &k, &n, &m);
    int a, b, t, h;
    REP(i, 0, m)
    {
        scanf("%d%d%d%d", &a, &b, &t, &h);
        adjL[a].push_back({b, t, h});
        adjL[b].push_back({a, t, h});
    }
    scanf("%d%d", &n1, &n2);
    pq.push({n1, 0, k});
    route cur;
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (cur.h <= hull[cur.n2])
        {
            continue;
        }
        hull[cur.n2] = cur.h;
        if (cur.n2 == n2)
        {
            printf("%d", cur.t);
            return 0;
        }
        for (route r : adjL[cur.n2])
        {
            if (cur.h > r.h)
            {
                pq.push({r.n2, cur.t + r.t, cur.h - r.h});
            }
        }
    }
    printf("-1");
}