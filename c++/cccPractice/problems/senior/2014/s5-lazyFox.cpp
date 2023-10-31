#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

struct edge
{
    int d, a, b;
    bool operator<(edge e)
    {
        return d < e.d;
    }
};

int n;
pii coord[2005];
edge el[2001005];
int dist[2005];
int t[2005], lt[2005];
int ne;

int getDist(pii p1, pii p2);

int main()
{
    scanf("%d", &n);
    ne = n * (n + 1) / 2;
    REP(i, 1, n)
    {
        scanf("%d%d", &coord[i].first, &coord[i].second);
    }
    REP(i, 1, n)
    {
        el[i] = {coord[i].first * coord[i].first + coord[i].second * coord[i].second, 0, i};
    }
    int ind = n + 1;
    REP(i, 1, n)
    {
        REP(j, i + 1, n)
        {
            el[ind++] = {getDist(coord[i], coord[j]), i, j};
        }
    }
    sort(el, el + ne);
    int curD, curA, curB;
    REP(i, 0, ne - 1)
    {
        edge &e = el[i];
        curD = e.d;
        curA = e.a, curB = e.b;
        if (curD > dist[curA])
        {
            dist[curA] = curD;
            lt[curA] = t[curA];
        }
        if (curD > dist[curB])
        {
            dist[curB] = curD;
            lt[curB] = t[curB];
        }
        if (curA == 0)
        {
            t[curA] = max(t[curA], lt[curB] + 1);
        }
        else
        {
            t[curA] = max(t[curA], lt[curB] + 1);
            t[curB] = max(t[curB], lt[curA] + 1);
        }
    }
    printf("%d", t[0]);
}

int getDist(pii p1, pii p2)
{
    return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);
}