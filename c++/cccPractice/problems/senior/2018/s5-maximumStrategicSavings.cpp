#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

struct edge
{
    int c, n1, n2;
    bool type;
    bool operator<(edge other)
    {
        return c < other.c;
    }
};

struct ufds
{
    int par[100005];

    int findSet(int node)
    {
        return (node == par[node]) ? node : (node = findSet(par[node]));
    }

    bool isSameSet(int n1, int n2)
    {
        return findSet(n1) == findSet(n2);
    }

    void unionSet(int n1, int n2)
    {
        if (isSameSet(n1, n2))
        {
            return;
        }
        par[findSet(n1)] = findSet(n2);
    }
};

int n, m, p, q;
ll totCost, minCost;
edge EL[200005];
ufds flight, portal;

int main()
{
    scanf("%d%d%d%d", &n, &m, &p, &q);
    REP(i, 0, p - 1)
    {
        scanf("%d%d%d", &EL[i].n1, &EL[i].n2, &EL[i].c);
        totCost += (ll)EL[i].c * n;
    }
    REP(i, 0, q - 1)
    {
        scanf("%d%d%d", &EL[p + i].n1, &EL[p + i].n2, &EL[p + i].c);
        EL[p + i].type = 1;
        totCost += (ll)EL[i].c * m;
    }
    sort(EL, EL + p + q);
    REP(i, 1, n)
    {
        portal.par[i] = i;
    }
    REP(i, 1, m)
    {
        flight.par[i] = i;
    }
    int remFlight = n, remPortal = m;
    for (const edge &e : EL)
    {
        if (!e.type && !flight.isSameSet(e.n1, e.n2))
        {
            flight.unionSet(e.n1, e.n2);
            minCost += (ll)e.c * remFlight;
            remPortal--;
        }
        else if (!portal.isSameSet(e.n1, e.n2))
        {
            portal.unionSet(e.n1, e.n2);
            minCost += (ll)e.c * remPortal;
            remFlight--;
        }
    }
    printf("%lld", totCost - minCost);
}