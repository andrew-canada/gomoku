#include <bits/stdc++.h>

using namespace std;

int build(int l, int r, int treeIdx, bool useOr);
void update(int l, int r, int treeIdx, bool useOr, int idx, int val);

int n = 2;
int num = pow(2, n);
int *arr = new int[num]{1, 2, 3, 4};
int *tree = new int[4 * num];

int main()
{
    build(0, num - 1, 0, n % 2 == 1);
    for (int i = 0; i < 4 * num; i++)
    {
        printf("%d ", tree[i]);
    }
    printf("\n");
}

int build(int l, int r, int treeIdx, bool useOr)
{
    if (l == r)
    {
        return tree[treeIdx] = arr[l];
    }
    int mid = (l + r) / 2;
    if (useOr)
    {
        return tree[treeIdx] = build(l, mid, 2 * treeIdx + 1, !useOr) | build(mid + 1, r, 2 * treeIdx + 2, !useOr);
    }
    else
    {
        return tree[treeIdx] = build(l, mid, 2 * treeIdx + 1, !useOr) ^ build(mid + 1, r, 2 * treeIdx + 2, !useOr);
    }
}

void update(int l, int r, int treeIdx, bool useOr, int idx, int val)
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
    if (useOr)
    {
        // tree[treeIdx] = update()|update()tree[2 * treeIdx + 1] | tree[2 * treeIdx + 2];
    }
    else
    {
        tree[treeIdx] = tree[2 * treeIdx + 1] ^ tree[2 * treeIdx + 2];
    }
}