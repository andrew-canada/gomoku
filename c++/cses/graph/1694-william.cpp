#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 5e2, mxM = 1e3, M = 1e9 + 7;

int n, m, d[mxN], p[mxN];
vector<int> adjL[mxN];

struct edge
{
    int u, v, rev, cap;
} e[2 * mxM];

int main()
{
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c, --a, --b;
        e[2 * i] = {a, b, 2 * i + 1, c};
        e[2 * i + 1] = {b, a, 2 * i, 0};
        adjL[a].pb(2 * i);
        adjL[b].pb(2 * i + 1);
    }
    ll f = 0;
    while (true)
    {
        memset(d, INF, sizeof(d));
        d[0] = 0;
        queue<int> q;
        q.push(0);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int i : adjL[u])
            {
                if (e[i].cap && d[e[i].v] > 1e9)
                {
                    d[e[i].v] = d[u] + 1;
                    p[e[i].v] = i;
                    q.push(e[i].v);
                }
            }
        }
        if (d[n - 1] > 1e9)
        {
            break;
        }
        int mf = 1e9, u = n - 1;
        while (u)
        {
            mf = min(mf, e[p[u]].cap);
            u = e[p[u]].u;
        }
        f += mf;
        u = n - 1;
        while (u)
        {
            e[p[u]].cap -= mf;
            e[e[p[u]].rev].cap += mf;
            u = e[p[u]].u;
        }
    }
    cout << f;
}