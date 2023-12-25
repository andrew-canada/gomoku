/*
n animals [1, 100]
m=n pens
pen:
 1. edges [3, 8]
 2. specify twice = connects two pens
 3. specify once = connects to outside
 4. one animal per pen, no animal outside pen
cost c to break an edge
minimize total cost of broken edges to gather all animal in one cell
*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

struct edge
{
    int a, b, w;
    bool operator<(const edge &e)
    {
        return w < e.w;
    }
};

struct UFDS
{
    int par[1005];
    vector<int> size = vector<int>(1005, 1);
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

int c[10];
vector<int> adjL[1005][1005];
vector<edge> el;
UFDS ufds;

int main()
{
    int m;
    int e;
    int w;
    int c1, c2;
    scanf("%d", &m);
    REP(i, 0, m)
    {
        scanf("%d", &e);
        REP(j, 0, e)
        {
            scanf("%d", &c[j]);
        }
        c[e] = c[0];
        REP(j, 0, e)
        {
            scanf("%d", &w);
            c1 = min(c[j], c[j + 1]), c2 = max(c[j], c[j + 1]);
            if (adjL[c1][c2].size() == 0)
            {
                adjL[c1][c2].push_back(w);
            }
            adjL[c1][c2].push_back(i);
        }
    }
    auto &cur = adjL[0][0];
    REP(i, 1, 1000 + 1)
    {
        REP(j, 1, 1000 + 1)
        {
            cur = adjL[i][j];
            if (cur.size() == 2)
            {
                el.push_back({cur[1], m, cur[0]});
            }
            else if (cur.size() == 3)
            {
                el.push_back({cur[1], cur[2], cur[0]});
            }
        }
    }
    REP(i, 0, 1000 + 1)
    {
        ufds.par[i] = i;
    }
    int ct1 = 0;
    int ne = 0;
    sort(el.begin(), el.end());
    for (const edge &ce : el)
    {
        if (ce.b == m || ufds.isSameSet(ce.a, ce.b))
        {
            continue;
        }
        ct1 += ce.w;
        ne++;
        ufds.unionSet(ce.a, ce.b);
        if (ne == m - 1)
        {
            break;
        }
    }

    REP(i, 0, 1000 + 1)
    {
        ufds.par[i] = i;
    }
    int ct2 = 0;
    ne = 0;
    for (const edge &ce : el)
    {
        if (ufds.isSameSet(ce.a, ce.b))
        {
            continue;
        }
        ct2 += ce.w;
        ne++;
        ufds.unionSet(ce.a, ce.b);
        if (ne == m)
        {
            break;
        }
    }
    printf("%d", min(ct1, ct2));
}