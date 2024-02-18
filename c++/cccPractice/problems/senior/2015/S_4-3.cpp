#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef array<int, 3> arri;

const int mxN = 2e3, mxK = 10;

int k, n, m;
vector<arri> adjL[mxN + 1];
int hull[mxN + 1];

int dijk(int u, int v)
{
    priority_queue<arri, vector<arri>, greater<arri>> pq;
    // time, hull, node
    pq.push({0, k, u});
    arri cur;
    while (pq.size())
    {
        cur = pq.top();
        pq.pop();
        // must be <= instead of < because < calculates unnecessary cases
        if (cur[1] <= hull[cur[2]])
        {
            continue;
        }
        hull[cur[2]] = cur[1];
        if (cur[2] == v)
        {
            return cur[0];
        }
        for (const arri &a : adjL[cur[2]])
        {
            if (cur[1] > a[1])
            {
                pq.push({cur[0] + a[0], cur[1] - a[1], a[2]});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> k >> n >> m;
    for (int i = 0, u, v, t, h; i < m; i++)
    {
        cin >> u >> v >> t >> h;
        adjL[u].pb({t, h, v});
        adjL[v].pb({t, h, u});
    }
    int u, v;
    cin >> u >> v;
    cout << dijk(u, v);
}