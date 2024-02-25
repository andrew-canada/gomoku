/*
binary tree with 2*i as left child and 2*i+1 as right child
each node is a range
*/

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 2e5;

int n, q;
int st[4 * mxN], arr[mxN];

void build(int ti = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
    {
        st[ti] = arr[tl];
    }
    else
    {
        int mid = (tl + tr) / 2;
        build(2 * ti, tl, mid);
        build(2 * ti + 1, mid + 1, tr);
        st[ti] = min(st[2 * ti], st[2 * ti + 1]);
    }
}

void update(int l, int val, int ti = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
    {
        st[ti] = val;
        return;
    }
    int mid = (tl + tr) / 2;
    if (l <= mid)
    {
        update(l, val, 2 * ti, tl, mid);
    }
    else
    {
        update(l, val, 2 * ti + 1, mid + 1, tr);
    }
    st[ti] = min(st[2 * ti], st[2 * ti + 1]);
}

int query(int l, int r, int ti = 1, int tl = 0, int tr = n - 1)
{
    if (tl >= l && tr <= r)
    {
        return st[ti];
    }
    int mid = (tl + tr) / 2;
    return min(l <= mid ? query(l, r, 2 * ti, tl, mid) : INF,
               r > mid ? query(l, r, 2 * ti + 1, mid + 1, tr) : INF);
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        update(i, arr[i]);
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << query(a - 1, b - 1) << '\n';
    }
}