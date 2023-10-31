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
    vector<int> size = vector<int>(100005, 1);
    // int size[100005];

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
        int p1 = findSet(n1), p2 = findSet(n2);
        if (size[p1] > size[p2])
        {
            par[p2] = p1;
            size[p1] += size[p2];
        }
        else
        {
            par[p1] = p2;
            size[p2] += size[p1];
        }
    }
};

int n, m, p, q;
ll totCost, minCost;
edge EL[200005];
ufds flight, portal;

int main()
{
    // freopen("s5.in", "r", stdin);
    // freopen("s5.out", "w", stdout);
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
        totCost += (ll)EL[p + i].c * m;
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
    int remPortal = n, remFlight = m;
    for (const edge &e : EL)
    {
        // printf("%lld\n", minCost);
        // printf("|%d %d\n", remPortal, remFlight);
        // printf("%d %d %d %d\n", e.n1, e.n2, e.c, e.type);
        if (!e.type && !flight.isSameSet(e.n1, e.n2))
        {
            flight.unionSet(e.n1, e.n2);
            minCost += (ll)e.c * remPortal;
            // printf("%d %d %lld\n", e.c, remPortal, minCost);
            remFlight--;
        }
        else if (e.type && !portal.isSameSet(e.n1, e.n2))
        {
            portal.unionSet(e.n1, e.n2);
            minCost += (ll)e.c * remFlight;
            // printf("%d %d %lld\n", e.c, remFlight, minCost);
            remPortal--;
        }
    }
    // printf("%lld %lld\n", totCost, minCost);
    printf("%lld", totCost - minCost);
}