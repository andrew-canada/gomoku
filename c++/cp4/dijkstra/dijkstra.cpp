#include <stdio.h>
#include <cstring>
#include <utility>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
typedef pair<int, int> pii;

int n, e, s;
int dist[5];
vector<pii> adjL[5];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
    freopen("dijkstra.in", "r", stdin);
    memset(dist, 100, sizeof(dist));

    scanf("%d%d%d", &n, &e, &s);
    int x, y, w;
    REP(i, 0, e)
    {
        scanf("%d%d%d", &x, &y, &w);
        adjL[x].emplace_back(y, w);
    }
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto [d1, n1] = pq.top();
        pq.pop();
        if (d1 > dist[n1])
        {
            continue;
        }
        for (auto [n2, w] : adjL[n1])
        {
            int d2 = d1 + w;
            if (d2 >= dist[n2])
            {
                continue;
            }
            dist[n2] = d2;
            pq.push({d2, n2});
        }
    }
    printf("%d", dist[n - 1]);
}