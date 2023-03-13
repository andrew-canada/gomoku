#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

class SegTree
{
private:
    int size;
    vi tree, treeVals;

    int glp(int pos)
    {
        return pos << 1;
    }
    int grp(int pos)
    {
        return (pos << 1) + 1;
    }

    void build(int pos, int l, int r)
    {
        if (l == r)
        {
            tree[pos] = treeVals[l];
        }
        else
        {
            int mid = (l + r) / 2;
            int lPos = glp(pos);
            int rPos = grp(pos);
            build(lPos, l, mid);
            build(rPos, mid + 1, r);
            tree[pos] = conquer(tree[lPos], tree[rPos]);
        }
    }
    int conquer(int a, int b)
    {
        if (a == -1)
        {
            return b;
        }
        else if (b == -1)
        {
            return a;
        }
        else
        {
            return min(a, b);
        }
    }
    int rmq(int pos, int l, int r, int i, int j)
    {
        if (i > j)
        {
            return -1;
        }
        if (l >= i && r <= j)
        {
            return tree[pos];
        }
        int mid = (l + r) / 2;
        return conquer(rmq(glp(pos), l, mid, i, min(j, mid)),
                       rmq(grp(pos), mid + 1, r, max(i, mid + 1), j));
    }

public:
    SegTree(int sz) : size(sz), tree(size * 4) {}
    SegTree(vi vals) : SegTree(vals.size())
    {
        treeVals = vals;
        build(1, 0, size - 1);
    }
    int rmq(int i, int j)
    {
        return rmq(1, 0, size - 1, i, j);
    }
};

int main()
{
    vi vals = {2, 6, 5, 3, 3, 7, 8, 1};
    SegTree st(vals);
    printf("rmq (0, 7): %d\n", st.rmq(0, 7));
}