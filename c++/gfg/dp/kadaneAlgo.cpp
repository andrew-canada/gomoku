#include <bits/stdc++.h>

using namespace std;

const int INF = -0x3f3f3f3f;
int dp[100];

int kadane(int *arr, int n)
{
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }
    return *max_element(dp, dp + n);
}

int main()
{
    int n = 7;
    int arr[7] = {2, 3, -7, 5, -1, 4, -3};
    printf("%d\n", kadane(arr, n));
}