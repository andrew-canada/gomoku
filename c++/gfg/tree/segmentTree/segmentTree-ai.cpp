#include <bits/stdc++.h>

using namespace std;

// function to sum query segment tree for range [l, r]
int sumQuery(int l, int r, int treeIdx, int lq, int rq)
{
    // if the current segment tree node is completely outside the query range
    if (l > rq || r < lq)
    {
        return 0;
    }
    // if the current segment tree node is completely inside the query range
    if (l >= lq && r <= rq)
    {
        return tree[treeIdx];
    }
    // if the current segment tree node is partially inside and partially outside the query range
    int mid = (l + r) / 2;
    return sumQuery(l, mid, 2 * treeIdx + 1, lq, rq) + sumQuery(mid + 1, r, 2 * treeIdx + 2, lq, rq);
}

// function to update segment tree for range [l, r]
void update(int l, int r, int treeIdx, int idx, int val)
{
    // if the current segment tree node is completely outside the query range
    if (l > idx || r < idx)
    {
        return;
    }
    // if the current segment tree node is completely inside the query range
    if (l == r)
    {
        tree[treeIdx] = val;
        return;
    }
    // if the current segment tree node is partially inside and partially outside the query range
    int mid = (l + r) / 2;
    update(l, mid, 2 * treeIdx + 1, idx, val);
    update(mid + 1, r, 2 * treeIdx + 2, idx, val);
    tree[treeIdx] = tree[2 * treeIdx + 1] + tree[2 * treeIdx + 2];
}