#include <bits/stdc++.h>

using namespace std;

int build(int l, int r, int treeIdx);
int sumQuery(int l, int r, int treeIdx, int ql, int qr);
void update(int l, int r, int treeIdx, int idx, int val);

int n = 4;
int *arr = new int[n]{1, 2, 3, 4};
int *tree = new int[4 * n];

int main()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    build(0, n - 1, 0);
    for (int i = 0; i < 4 * n; i++)
    {
        printf("%d ", tree[i]);
    }
    printf("\n");
    printf("%d\n", sumQuery(0, n - 1, 0, 1, 3));
    printf("%d\n", sumQuery(0, n - 1, 0, 0, 1));
    printf("%d\n", sumQuery(0, n - 1, 0, 3, 3));
    printf("%d\n", sumQuery(0, n - 1, 0, 0, 4));
    printf("\n");

    update(0, n - 1, 0, 1, -2);
    printf("%d\n", sumQuery(0, n - 1, 0, 1, 3));
    printf("%d\n", sumQuery(0, n - 1, 0, 0, 1));
    printf("%d\n", sumQuery(0, n - 1, 0, 3, 3));
    printf("%d\n", sumQuery(0, n - 1, 0, 0, 4));
}

int build(int l, int r, int treeIdx)
{
    if (l == r)
    {
        return tree[treeIdx] = arr[l];
    }
    int mid = (l + r) / 2;
    return tree[treeIdx] = build(l, mid, 2 * treeIdx + 1) + build(mid + 1, r, 2 * treeIdx + 2);
}

int sumQuery(int l, int r, int treeIdx, int ql, int qr)
{
    if (l > qr || r < ql)
    {
        return 0;
    }
    if (l >= ql && r <= qr)
    {
        return tree[treeIdx];
    }
    int mid = (l + r) / 2;
    return sumQuery(l, mid, 2 * treeIdx + 1, ql, qr) + sumQuery(mid + 1, r, 2 * treeIdx + 2, ql, qr);
}

void update(int l, int r, int treeIdx, int idx, int val)
{
    if (l > idx || r < idx)
    {
        return;
    }
    if (l == r)
    {
        tree[treeIdx] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, 2 * treeIdx + 1, idx, val);
    update(mid + 1, r, 2 * treeIdx + 2, idx, val);
    tree[treeIdx] = tree[2 * treeIdx + 1] + tree[2 * treeIdx + 2];
}