#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

struct Pipe
{
    int b1, b2, c, num;
    bool operator<(Pipe p)
    {
        return c == p.c ? num < p.num : c < p.c;
    }
};

struct UFDS
{
    int par[100005];
    vector<int> size = vector<int>(100005, 1);

    int findSet(int p)
    {
        return (p == par[p]) ? p : (par[p] = findSet(par[p]));
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
Pipe pipes[200005];
UFDS ufds;

int main()
{
    int b1, b2, c;
    scanf("%d%d%d", &n, &m, &d);
    REP(i, 1, m)
    {
        scanf("%d%d%d", &b1, &b2, &c);
        pipes[i] = {b1, b2, c, i};
    }
    REP(i, 1, n)
    {
        ufds.par[i] = i;
    }
    sort(pipes + 1, pipes + m + 1);
    int numP = 0;
    int newP = 0;
    int maxP = 0;
    REP(i, 1, m)
    {
        Pipe p = pipes[i];
        if (numP == n - 1)
        {
            break;
        }
        if (ufds.isSameSet(p.b1, p.b2))
        {
            continue;
        }
        numP++;
        ufds.unionSet(p.b1, p.b2);
        if (p.num > n - 1)
        {
            newP++;
        }
        maxP = p.c;
    }

    REP(i, 1, n)
    {
        ufds.par[i] = i;
    }
    REP(i, 1, m)
    {
        Pipe p = pipes[i];
        if (ufds.isSameSet(p.b1, p.b2))
        {
            continue;
        }
        if (p.c < maxP || (p.c == maxP && p.num <= n - 1))
        {
            ufds.unionSet(p.b1, p.b2);
        }
        else if (p.c <= d && p.num <= n - 1)
        {
            newP--;
            break;
        }
    }
    printf("%d", newP);
}