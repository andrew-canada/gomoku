#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 2e14

typedef long long ll;

const int mxN = 1e5;

vector<array<int, 2>> adjL[mxN + 1];
ll dist[mxN + 1];
priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;

void dijk()
{
    pq.push({0, 1});
    array<ll, 2> cur;
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (cur[0] > dist[cur[1]])
        {
            continue;
        }
        for (array<int, 2> arr : adjL[cur[1]])
        {
            ll newDist = cur[0] + arr[0];
            if (newDist < dist[arr[1]])
            {
                dist[arr[1]] = newDist;
                pq.push({newDist, arr[1]});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        adjL[a].pb({c, b});
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[1] = 0;
    dijk();
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}