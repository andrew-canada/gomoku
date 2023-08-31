#include <stdio.h>
#include <vector>
#include <numeric>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 150005

int n, m;
int seq[INF];
int st[4 * INF];
int req[INF][3];

void build(int cur, int l, int r);
int query(int cur, int tl, int tr, int l, int r);

int main()
{
    scanf("%d%d", &n, &m);
    REP(i, 0, m - 1)
    {
        scanf("%d%d%d", &req[i][0], &req[i][1], &req[i][2]);
    }
    build(1, 1, n);
}

void build(int cur, int l, int r)
{
    if (l == r)
    {
        st[cur] = seq[l];
    }
    else
    {
        int mid = (l + r) / 2;
        build(cur * 2, l, mid);
        build(cur * 2 + 1, mid + 1, r);
        st[cur] = gcd(st[cur * 2], st[cur * 2 + 1]);
    }
}

int query(int cur, int tl, int tr, int l, int r)
{
    if (r < tl || tr < l)
    {
        return 0;
    }
    if (l < tl && tr <= r)
    {
        return st[cur];
    }
    int tm = (tl + tr) / 2;
    // return gcd(query);
}