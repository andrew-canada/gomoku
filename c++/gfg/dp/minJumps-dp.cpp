#include <bits/stdc++.h>

using namespace std;

int mj(int *arr, int n, int i);

const int INF = 0x3f3f3f3f;
int dp[100];

int main()
{
    // freopen("minJumps.out", "w", stdout);
    int n = 5;
    int arr[5] = {3, 2, 2, 1, 5};
    memset(dp, -1, sizeof(dp));
    printf("%d\n", mj(arr, 5, 0));
}

int mj(int *arr, int n, int i)
{
    if (i >= n - 1)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int jumps = INF;
    for (int j = 1; j <= arr[i]; j++)
    {
        jumps = min(jumps, 1 + mj(arr, n, i + j));
    }
    return dp[i] = jumps;
}