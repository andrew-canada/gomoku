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
typedef long long ll;

ll cost = 0;
int n = 0, e = 0;
int n1, n2, l, c;
ll dist[2005];
vector<iiii> roads;
vector<pii> adjL[2005];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    // freopen("s4.in", "r", stdin);
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
        pii e1 = {get<1>(r), get<2>(r)};
        pii e2 = {get<1>(r), get<3>(r)};
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

        memset(dist, 0x7f, sizeof(dist));
        dist[get<2>(r)] = 0;
        pq.push(get<2>(r));
        while (!pq.empty())
        {
            int cur = pq.top();
            pq.pop();
            for (auto [w, node] : adjL[cur])
            {
                ll d = dist[cur] + w;
                if (d < dist[node])
                {
                    dist[node] = d;
                    pq.push(node);
                }
            }
        }
        if (get<1>(r) < dist[get<3>(r)])
        {
            adjL[get<2>(r)].emplace_back(e2);
            adjL[get<3>(r)].emplace_back(e1);
            cost += get<0>(r);
        }
    }
    printf("%lld", cost);
}