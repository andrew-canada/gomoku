#include <bits/stdc++.h>

using namespace std;

const int mxN = 3e3, mxM = 105;

int p1[mxN + 1], p2[mxN + 1];
int dp[mxN + 1][2];
int n, m;

int maxS(int n1, bool canTake);

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p1[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &p2[i]);
    }
    sort(p2, p2 + m);
    printf("%d", maxS(0, true));
}

int maxS(int n1, bool canTake)
{
    int totS = 0;
    if (dp[n][canTake])
    {
        return dp[n][canTake];
    }
    if (n1 >= n)
    {
        return totS;
    }
    if (canTake)
    {
        totS += max(maxS(n1 + 1, true), maxS(n1 + 1, false));
    }
    else
    {
        totS += maxS(n1 + 1, true);
    }
    return dp[n][canTake] = max(dp[n][canTake], totS);
}

/*
5
10
12
6
14
7
3
1
8
2
*/