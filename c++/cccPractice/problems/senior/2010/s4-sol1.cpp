#include <bits/stdc++.h>
using namespace std;

const int MN = 105;
map<pair<int, int>, int> id;
int n, m[MN], w[MN][10], a[MN][10], i, j, x, ds[MN], ans1, ans2;
int fnd(int x) { return ds[x] = ds[x] == x ? x : fnd(ds[x]); }
struct edge
{
    int x, y, w;
};
vector<edge> vec;

int main()
{
    for (scanf("%d", &n), i = 1; i <= n; i++)
    {
        ds[i] = i;
        for (scanf("%d", &m[i]), j = 0; j < m[i]; j++)
            scanf("%d", &a[i][j]);
        for (j = 0; j < m[i]; j++)
            scanf("%d", &w[i][j]);
        for (j = 0; j < m[i]; j++)
        {
            pair<int, int> p = {a[i][j], a[i][(j + 1) % m[i]]};
            if (p.second < p.first)
                swap(p.first, p.second);
            if (id.count(p))
            {
                int ID = id[p];
                vec.push_back({i, ID, w[i][j]});
                id[p] = -1;
            }
            else
                id[p] = i;
        }
    }
    sort(vec.begin(), vec.end(), [](edge i, edge j)
         { return i.w < j.w; });
    for (auto v : vec)
    {
        int x = v.x, y = v.y, w = v.w;
        if (fnd(x) != fnd(y))
        {
            ds[fnd(x)] = fnd(y);
            ans1 += w;
        }
    }
    for (i = 1; i <= n; i++)
    {
        ds[i] = i;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < m[i]; j++)
        {
            pair<int, int> p = {a[i][j], a[i][(j + 1) % m[i]]};
            if (p.second < p.first)
                swap(p.first, p.second);
            if (id[p] != -1)
            {
                vec.push_back({i, 0, w[i][j]});
            }
        }
    }
    sort(vec.begin(), vec.end(), [](edge i, edge j)
         { return i.w < j.w; });
    for (auto v : vec)
    {
        int x = v.x, y = v.y, w = v.w;
        if (fnd(x) != fnd(y))
        {
            ds[fnd(x)] = fnd(y);
            ans2 += w;
        }
    }
    printf("%d\n", min(ans1, ans2));
    return 0;
}