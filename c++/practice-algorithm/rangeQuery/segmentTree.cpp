/*
binary tree with 2*i as left child and 2*i+1 as right child
each node is a range
*/

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 100;

int n;
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
        st[ti] = max(st[2 * ti], st[2 * ti + 1]);
    }
}

void update(int l, int val, int ti = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
    {
        st[ti] = val;
    }
    int mid = (tl + tr) / 2;
    if (l <= mid)
    {
        update(l, val, 2 * ti, tl, mid);
    }
    else
    {
        update(l, val, 2 * ti, mid + 1, tr);
    }
    st[ti] = max(st[2 * ti], st[2 * ti + 1]);
}

int query(int l, int r, int ti = 1, int tl = 0, int tr = n - 1)
{
    if (l >= tl && r <= tr)
    {
        return st[ti];
    }
    int mid = (tl + tr) / 2;
    return max(l <= mid ? query(l, r, 2 * ti, tl, mid) : 0,
               r > mid ? query(l, r, 2 * ti + 1, mid + 1, tr) : 0);
}

int main()
{
}