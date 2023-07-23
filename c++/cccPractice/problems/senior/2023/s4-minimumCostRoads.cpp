#include <stdio.h>
#include <vector>
#include <utility>
#include <tuple>
#include <queue>
#include <functional>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef pair<int, int> pii;
typedef tuple<int, int, int, int> iiii;

int cost = 0, n = 0, e = 0;
int n1, n2, l, c;
int dist[2005];
vector<iiii> roads;
vector<pii> adjL[2005];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
    scanf("%d%d", &n, &e);
    REP(i, 0, e)
    {
        scanf("%d%d%d%d", &n1, &n2, &l, &c);
        adjL[n1].emplace_back(l, n2);
        adjL[n2].emplace_back(l, n1);
        roads.emplace_back(iiii(c, l, n1, n2));
    }
    sort(roads.begin(), roads.end(), greater<iiii>());
    for (iiii r : roads)
    {
        pii e1 = {get<0>(r), get<2>(r)};
        pii e2 = {get<0>(r), get<3>(r)};
        for (auto it = adjL[get<2>(r)].begin(); it != adjL[get<2>(r)].end(); it++)
        {
            if (*it == e2)
            {
                adjL[get<2>(r)].erase(it);
                break;
            }
        }
        for (auto it = adjL[get<3>(r)].begin(); it != adjL[get<3>(r)].end(); it++)
        {
            if (*it == e1)
            {
                adjL[get<3>(r)].erase(it);
                break;
            }
        }

        memset(dist, 2e9, sizeof(dist));
        dist[get<2>(r)] = 0;
        pq.push({0, get<2>(r)});
        while (!pq.empty())
        {
            auto [d1, node1] = pq.top();
            pq.pop();
            if (d1 > dist[node1])
            {
                continue;
            }
            for (auto [w, node2] : adjL[node1])
            {
                int d2 = d1 + w;
                if (d2 >= dist[node2])
                {
                    continue;
                }
                dist[node2] = d2;
                pq.push({d2, node2});
            }
        }
        if (get<1>(r) < dist[get<3>(r)])
        {
            adjL[get<2>(r)].emplace_back(e2);
            adjL[get<3>(r)].emplace_back(e1);
            cost += get<0>(r);
        }
    }
    printf("%d", cost);
}