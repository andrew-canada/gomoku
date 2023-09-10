#include <stdio.h>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

struct Road
{
    int n1, n2, l, c;
    bool operator<(Road r)
    {
        return l == r.l ? c < r.c : l < r.l;
    }
};

int n, e;
Road roads[2005];
vector<pii> adjL[2005];
priority_queue<pll, vector<pll>, greater<pll>> pq;
ll dist[2005];
ll cost;

ll dijkstra(int n1, int n2);

int main()
{
    int n1, n2, l, c;
    scanf("%d%d", &n, &e);
    REP(i, 0, e - 1)
    {
        scanf("%d%d%d%d", &n1, &n2, &l, &c);
        roads[i] = {n1, n2, l, c};
    }
    sort(roads, roads + e);
    for (Road r : roads)
    {
        if (r.l < dijkstra(r.n1, r.n2))
        {
            adjL[r.n1].push_back({r.l, r.n2});
            adjL[r.n2].push_back({r.l, r.n1});
            cost += r.c;
        }
    }
    printf("%lld", cost);
}

ll dijkstra(int n1, int n2)
{
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[n1] = 0;
    pq.push({0, n1});
    while (!pq.empty())
    {
        auto [len, node] = pq.top();
        pq.pop();
        if (len > dist[node])
        {
            continue;
        }
        for (auto [len2, node2] : adjL[node])
        {
            ll totLen = len + len2;
            if (totLen < dist[node2])
            {
                dist[node2] = totLen;
                pq.push({totLen, node2});
            }
        }
    }
    return dist[n2];
}