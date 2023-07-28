#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Road
{
    int n1, n2, l, c;
    bool operator<(Road r)
    {
        return l == r.l ? c < r.c : l < r.l;
    }
};

int n, e;
ll cost = 0;
vector<pii> adjL[2005];
Road roads[2005];
ll dist[2005];
priority_queue<pll, vector<pll>, greater<pll>> pq;

ll dijkstra(int n1, int n2);

int main()
{
    scanf("%d%d", &n, &e);
    int n1, n2, l, c;
    REP(i, 0, e)
    {
        scanf("%d%d%d%d", &n1, &n2, &l, &c);
        roads[i] = {--n1, --n2, l, c};
    }
    sort(roads, roads + e);
    for (Road r : roads)
    {
        if (r.l < dijkstra(r.n1, r.n2))
        {
            adjL[r.n1].push_back({r.n2, r.l});
            adjL[r.n2].push_back({r.n1, r.l});
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
        auto [l, nn1] = pq.top();
        pq.pop();
        if (dist[nn1] != l)
        {
            continue;
        }
        for (auto [nn2, w] : adjL[nn1])
        {
            ll l2 = w + l;
            if (l2 < dist[nn2])
            {
                dist[nn2] = l2;
                pq.push({l2, nn2});
            }
        }
    }
    return dist[n2];
}