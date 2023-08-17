#include <stdio.h>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

typedef tuple<int, int, int> iii;

int k, n, m;
int n1, n2;
int dist[2005][2005];
vector<iii> adjL[10005];
priority_queue<iii, vector<iii>, greater<iii>> pq;

int main()
{
    freopen("s4.in", "r", stdin);
    freopen("s4.out", "w", stdout);
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
    while (!pq.empty())
    {
        iii cur = pq.top();
        pq.pop();
        if (get<0>(cur) > dist[get<2>(cur)][get<1>(cur)])
        {
            continue;
        }
        if (get<2>(cur) == n2)
        {
            printf("%d", get<0>(cur));
            return 0;
        }
        for (iii r : adjL[get<2>(cur)])
        {
            if (get<1>(r) < get<1>(cur))
            {
                int dmg = get<1>(cur) - get<1>(r);
                int time = get<0>(r) + get<0>(cur);
                dist[get<2>(r)][dmg] = time;
                pq.push({time, dmg, get<2>(r)});
            }
        }
    }
    printf("-1");
}