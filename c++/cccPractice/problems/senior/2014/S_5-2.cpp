#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 2e3, mxM = 2001000;

struct edge
{
    int u, v, d;
    bool operator<(const edge &e)
    {
        return d < e.d;
    }
};

int dist[mxN + 5];
array<int, 2> coord[mxN + 5];
edge el[mxM + 5];
int ct[mxN + 5], pt[mxN + 1];

int main()
{
    int n;
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        coord[i] = {x, y};
    }
    int num = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            el[num] = {i,
                       j,
                       (coord[j][0] - coord[i][0]) * (coord[j][0] - coord[i][0]) +
                           (coord[j][1] - coord[i][1]) * (coord[j][1] - coord[i][1])};
            num++;
        }
    }
    sort(el, el + num);
    edge cur;
    for (int i = 0; i < num; i++)
    {
        cur = el[i];
        if (cur.d > dist[cur.u])
        {
            dist[cur.u] = cur.d;
            pt[cur.u] = ct[cur.u];
        }
        if (cur.d > dist[cur.v])
        {
            dist[cur.v] = cur.d;
            pt[cur.v] = ct[cur.v];
        }
        if (cur.u == 0)
        {
            ct[0] = max(ct[0], pt[cur.v] + 1);
        }
        else
        {
            ct[cur.u] = max(ct[cur.u], pt[cur.v] + 1);
            ct[cur.v] = max(ct[cur.v], pt[cur.u] + 1);
        }
    }
    cout << ct[0];
}