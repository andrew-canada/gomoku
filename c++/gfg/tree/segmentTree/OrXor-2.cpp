#include <bits/stdc++.h>

using namespace std;

int update(int l, int r, int ql, int qr, int treeIdx, int val);

int n = 2;
int num = pow(2, n);
int *arr = new int[num]{1, 2, 3, 4};
int *tree = new int[4 * num];
pair<int, int> query[2] = {{1, 1}, {3, 1}};
bool useOr;

int main()
{
    for (int i = 0; i < num; i++)
    {
        update(0, num - 1, i, i, 0, arr[i]);
    }
    printf("tree: ");
    for (int i = 0; i < 4 * num; i++)
    {
        printf("%d ", tree[i]);
    }
    printf("\n");
    for (pair<int, int> p : query)
    {
        update(0, num - 1, p.first, p.first, 0, p.second);
        printf("tree: ");
        for (int i = 0; i < 4 * num; i++)
        {
            printf("%d ", tree[i]);
        }
        printf("\n");
    }
}

int update(int l, int r, int ql, int qr, int treeIdx, int val)
{
    if (l > qr || r < ql)
    {
        return 0;
    }
    if (l == r)
    {
        useOr = true;
        return tree[treeIdx] = val;
    }
    update(l, (l + r) >> 1, ql, qr, (treeIdx << 1) + 1, val);
    update(((l + r) >> 1) + 1, r, ql, qr, (treeIdx << 1) + 2, val);
    if (useOr)
    {
        tree[treeIdx] = tree[(treeIdx << 1) + 1] | tree[(treeIdx << 1) + 2];
    }
    else
    {
        tree[treeIdx] = tree[(treeIdx << 1) + 1] ^ tree[(treeIdx << 1) + 2];
    }
    useOr = !useOr;
}