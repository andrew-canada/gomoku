#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int n, w, d;
bool vis[200005];
int dist[200005];
int stn[200005];
int ind[200005];
vector<int> wAdj[200005];
queue<int> path;
multiset<int> time;

int main()
{
    memset(dist, 100, sizeof(dist));
    scanf("%d%d%d", &n, &w, &d);
    int n1, n2;
    REP(i, 1, w)
    {
        scanf("%d%d", &n1, &n2);
        wAdj[n2].push_back(n1);
    }

    vis[n] = true;
    dist[n] = 0;
    path.push(n);
    while (!path.empty())
    {
        int cur = path.front();
        path.pop();
        for (int ww : wAdj[cur])
        {
            if (!vis[ww])
            {
                dist[ww] = dist[cur] + 1;
                vis[ww] = true;
                path.push(ww);
            }
        }
    }
    REP(i, 1, n)
    {
        scanf("%d", &stn[i]);
        ind[stn[i]] = i - 1;
    }
    REP(i, 1, n)
    {
        time.insert(ind[i] + dist[i]);
    }
    int sn1, sn2;
    int st1, st2;
    REP(i, 1, d)
    {
        scanf("%d%d", &sn1, &sn2);
        st1 = stn[sn1];
        st2 = stn[sn2];
        time.erase(time.lower_bound(ind[st1] + dist[st1]));
        time.erase(time.lower_bound(ind[st2] + dist[st2]));
        swap(ind[st1], ind[st2]);
        swap(stn[sn1], stn[sn2]);
        time.insert(ind[st1] + dist[st1]);
        time.insert(ind[st2] + dist[st2]);
        printf("%d\n", *time.begin());
    }
}
