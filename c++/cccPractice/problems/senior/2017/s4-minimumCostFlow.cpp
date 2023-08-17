#include <stdio.h>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

struct Pipe
{
    int w, n, b1, b2;
    bool operator<(Pipe p)
    {
        return w == p.w ? n < p.n : w < p.w;
    }
};

int n, m, d;
int par[100005];
vector<Pipe> pipes;

int findSet(int p)
{
    return (par[p] == p) ? p : (par[p] = findSet(par[p]));
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
    par[par1] = par2;
}

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    REP(i, 1, m)
    {
        int b1, b2, w;
        scanf("%d%d%d", &b1, &b2, &w);
        pipes.push_back(Pipe({w, i, b1, b2}));
    }
    sort(pipes.begin(), pipes.end());
    REP(i, 1, n)
    {
        par[i] = i;
    }
    int numP = 0;
    int maxP = 0;
    int newP = 0;
    for (Pipe p : pipes)
    {
        if (numP == n - 1)
        {
            break;
        }
        if (isSameSet(p.b1, p.b2))
        {
            continue;
        }
        numP++;
        unionSet(p.b1, p.b2);
        if (p.n > n - 1)
        {
            newP++;
        }
        maxP = p.w;
    }

    memset(par, 0, sizeof(par));
    REP(i, 1, n)
    {
        par[i] = i;
    }
    for (Pipe p : pipes)
    {
        if (isSameSet(p.b1, p.b2))
        {
            continue;
        }
        if (p.w < maxP || (p.w == maxP && p.n <= n - 1))
        {
            unionSet(p.b1, p.b2);
        }
        else if (p.w <= d && p.n <= n - 1)
        {
            newP--;
            break;
        }
    }
    printf("%d", newP);
}