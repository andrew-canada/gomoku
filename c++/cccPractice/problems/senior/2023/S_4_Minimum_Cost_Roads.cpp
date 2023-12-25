/*
n node, m edge
edge i has length l(i) and len c(i)
remove some edges to minimize len
new graph: dist from a to b must be less than or equal to current distance
output min len of new graph
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<ll, ll> pll;

struct edge
{
    int a, b, l, c;
    bool operator<(const edge &e)
    {
        return l == e.l ? c < e.c : l < e.l;
    }
};

edge el[2005];
vector<pll> adjL[2005];
priority_queue<pll, vector<pll>, greater<pll>> pq;
ll len[2005];
ll mc;

ll dijk(int a, int b);

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    REP(i, 0, m)
    {
        scanf("%d%d%d%d", &el[i].a, &el[i].b, &el[i].l, &el[i].c);
    }
    sort(el, el + m);
    for (edge e : el)
    {
        if (e.l < dijk(e.a, e.b))
        {
            adjL[e.a].pb({e.b, e.l});
            adjL[e.b].pb({e.a, e.l});
            mc += e.c;
        }
    }
    printf("%lld", mc);
}

ll dijk(int a, int b)
{
    ll nc;
    memset(len, INF, sizeof(len));
    pll cur;
    pq.push({a, 0});
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (cur.second > len[cur.first])
        {
            continue;
        }
        for (pll e : adjL[cur.first])
        {
            nc = cur.second + e.second;
            if (nc < len[e.first])
            {
                len[e.first] = nc;
                pq.push({e.first, nc});
            }
        }
    }
    return len[b];
}