/*
1. build adjacency list where tar[i][j] is the 2^j-th parent of node i
    a) 2^n-th parent of node x is same as 2^(n-1)-th parent of the 2^(n-1)-th parent of x
2. use method similar to binary exponentiation
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int mxN = 10, M = 1e9 + 7;

int tar[mxN + 1][mxN + 1];

int main()
{
    tar[1][0] = 2, tar[2][0] = 3, tar[3][0] = 4, tar[4][0] = 5, tar[5][0] = 6;
    for (int i = 1; i < mxN; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            tar[j][i] = tar[tar[j][i - 1]][i - 1];
        }
    }
    int k = 5, ans;
    for (int i = 0; i < mxN; i++)
    {
        if ((k >> i) & 1)
        {
            ans = tar[1][i];
        }
    }
    cout << ans;
}