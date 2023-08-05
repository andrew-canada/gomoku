#include <stdio.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, w, d;
bool vis[200005];
int dist[200005];
int sub[200005];
vector<int> wAdj[200005];
queue<int> path;
multiset<int> time;

int main()
{
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
    int station;
    REP(i, 0, n)
    {
        scanf("%d", &station);
        }
}
