#include <iostream>

using namespace std;

// prefix sum array is sum of first n values : can calculate sum of index x to y
// 1,2,3
// 1,3,6

// segment tree stores info about intervals/segements : similar to binary tree

const int MN = 2e5 + 5;
const int BSZ = 600;
const int BC = 350;
int n, qccp1;
int arr[MN];
int blocks[BC];

// set position p to v
void upd(int p, int v)
{
    arr[p] = v;
    int block = i / BSZ;
    int newVal = 0;
    for (int i = block * BSZ; i < (block + 1) * BSZ; i++)
    {
        newVal = max(newVal, arr[i]);
    }
}

// max of [l, r)
int query(int l, int r)
{
    int res = 0;
    int lBlock = (b + BSZ - 1) / BSZ;
    int rBlock = r / BSZ;
    for (int i = lBlock; i < rBlock; i++)
    {
        res = max(res, blocks[i]);
    }
    for (int i = l; i < lBlock * BSZ; i++)
    {
        res = max(res, arr[i]);
    }
    for (int i = rBlock * BSZ; i < r; i++)
    {
        res = max(res, arr[i]);
    }
    return res;
}