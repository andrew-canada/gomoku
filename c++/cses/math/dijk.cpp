#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef unsigned long long ull;
typedef vector<vector<ull>> mat;

const int mxN = 100, M = 1e9 + 7;

struct edge
{
    ull a, d, b;
    bool operator<(const edge &e)
    {
        return a == e.a ? d < e.d : a < e.a;
    }
};

edge el[mxN * mxN];
vector<array<ull, 2>> adjL[mxN + 1];
ull dist[mxN + 1];

void dijk(int a, int b)
{
    memset(dist, INF, sizeof(dist));
    // {dist, tar}
    priority_queue<array<ull, 2>, vector<array<ull, 2>>, greater<array<ull, 2>>> pq;
    pq.push({0, 1});
    array<ull, 2> cur;
    dist[1] = 0;
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (cur[0] > dist[cur[1]])
        {
            continue;
        }
        // for (edge e : el)
        for (array<ull, 2> e : adjL[cur[1]])
        {
            ull d = cur[0] + e[1];
            if (d < dist[e[0]])
            {
                pq.push({d, e[0]});
                dist[e[0]] = d;
            }
        }
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        ull a, b, d;
        cin >> a >> b >> d;
        el[i] = {a, d, b};
    }
    sort(el, el + m);
    for (edge e : el)
    {
        adjL[e.a].pb({e.b, e.d});
    }
    dijk(1, n);
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << '\n';
    }
}