#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, w, d;
bool vis[200005];
int dist[200005];
int stn[200005];
vector<int> wAdj[200005];
queue<int> path;
multiset<int> time;

int main()
{
    memset(dist, 0, sizeof(dist));
    scanf("%d%d%d", &n, &w, &d);
    int n1, n2;
    REP(i, 0, w)
    {
        scanf("%d%d", &n1, &n2);
        wAdj[n1].push_back(n2);
    }

    vis[0] = true;
    path.push(0);
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
    REP(i, 0, n)
    {
        scanf("%d", &stn[i]);
        time.insert(i + dist[stn[i]]);
    }
    int sn1, sn2;
    int st1, st2;
    int l1, l2;
    REP(i, 0, d)
    {
        scanf("%d%d", &sn1, &sn2);
        st1 = stn[sn1];
        st2 = stn[sn2];
        l1 = sn1 - 1 + dist[st1];
        l2 = sn2 - 1 + dist[st2];
        time.erase(time.find(l1));
        time.erase(time.find(l2));
        swap(st1, st2);
        time.insert(sn1 - 1 + dist[st1]);
        time.insert(sn2 - 1 + dist[st2]);
        printf("%d", *time.begin());
    }
}
