#include <bits/stdc++.h>

using namespace std;

int *st;

void update(int l, int r, int ql, int qr, int treeIdx, int val);
int query(int l, int r, int lq, int qr, int treeIdx);

int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int len = s.length();
    st = new int[4 * len];
    for (int i = 0; i < len; i++)
    {
        update(0, len - 1, i, i, 0, 1 << (s[i] - 'a'));
    }
    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int idx;
            char c;
            cin >> idx >> c;
            update(0, len - 1, idx, idx, 0, 1 << (c - 'a'));
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << __builtin_popcount(query(0, len - 1, l, r, 0)) << '\n';
        }
    }
}

void update(int l, int r, int ql, int qr, int treeIdx, int val)
{
    if (l > qr || r < ql)
    {
        return;
    }
    if (l == r)
    {
        st[treeIdx] = val;
        return;
    }
    update(l, (l + r) >> 1, ql, qr, (treeIdx << 1) + 1, val);
    update(((l + r) >> 1) + 1, r, ql, qr, (treeIdx << 1) + 2, val);
    st[treeIdx] = st[(treeIdx << 1) + 1] | st[(treeIdx << 1) + 2];
}

int query(int l, int r, int ql, int qr, int treeIdx)
{
    if (l > qr || r < ql)
    {
        return 0;
    }
    if (l >= ql && r <= qr)
    {
        return st[treeIdx];
    }
    int lv = query(l, (l + r) >> 1, ql, qr, (treeIdx << 1) + 1);
    int rv = query(((l + r) >> 1) + 1, r, ql, qr, (treeIdx << 1) + 2);
    return lv | rv;
}