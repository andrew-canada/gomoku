#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

struct pipe
{
    int a, b, c, n;
    bool operator<(pipe &p)
    {
        return c == p.c ? n < p.n : c < p.c;
    }
};

struct UFDS
{
    int par[100005];
    vector<int> size = vector<int>(100005, 1);
    int findSet(int p)
    {
        return p == par[p] ? p : par[p] = findSet(par[p]);
    }
    bool isSameSet(int p1, int p2)
    {
        return findSet(p1) == findSet(p2);
    }
    void unionSet(int p1, int p2)
    {
        if (isSameSet(p1, p2))
        {
            return;
        }
        int par1 = findSet(p1), par2 = findSet(p2);
        if (size[par1] > size[par2])
        {
            par[par2] = par1;
            size[par1] += size[par2];
        }
        else
        {
            par[par1] = par2;
            size[par2] += size[par1];
        }
    }
};

int n, m, d;
int days;
pipe pipes[200005];
UFDS ufds;
int np;
int maxP;

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    REP(i, 1, m)
    {
        scanf("%d%d%d", &pipes[i].a, &pipes[i].b, &pipes[i].c);
        pipes[i].n = i;
    }
    REP(i, 1, n)
    {
        ufds.par[i] = i;
    }
    sort(pipes + 1, pipes + m + 1);
    REP(i, 1, m)
    {
        if (np == n - 1)
        {
            break;
        }
        pipe p = pipes[i];
        if (ufds.isSameSet(p.a, p.b))
        {
            continue;
        }
        np++;
        ufds.unionSet(p.a, p.b);
        if (p.n >= n)
        {
            days++;
        }
        maxP = p.c;
    }

    REP(i, 1, n)
    {
        ufds.par[i] = i;
    }
    REP(i, 1, m)
    {
        pipe p = pipes[i];
        if (ufds.isSameSet(p.a, p.b))
        {
            continue;
        }
        if (p.c < maxP || (p.c == maxP && p.n < n))
        {
            ufds.unionSet(p.a, p.b);
        }
        else if (p.c <= d && p.n < n)
        {
            days--;
            break;
        }
    }
    printf("%d", days);
}