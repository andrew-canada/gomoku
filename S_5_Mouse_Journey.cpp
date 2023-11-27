// r by c grid, r and c <=25
// find number of path from top left (1, 1) to bottom right
// can only move right or down
// k positions are blocked

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int r, c;
int k;
int dp[30][30];
bool cat[30][30];

int np(int r1, int c1);

int main()
{
    int r1, c1;
    scanf("%d%d%d", &r, &c, &k);
    REP(i, 0, k)
    {
        scanf("%d%d", &r1, &c1);
        cat[r1][c1] = 1;
    }
    printf("%d", np(1, 1));
}

int np(int r1, int c1)
{
    if (r1 == r && c1 == c)
    {
        return 1;
    }
    if (cat[r1][c1])
    {
        return 0;
    }
    if (dp[r1][c1])
    {
        return dp[r1][c1];
    }
    if (r1 + 1 <= r)
    {
        dp[r1][c1] += np(r1 + 1, c1);
    }
    if (c1 + 1 <= c)
    {
        dp[r1][c1] += np(r1, c1 + 1);
    }
    return dp[r1][c1];
}