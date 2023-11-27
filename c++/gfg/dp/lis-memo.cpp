#include <bits/stdc++.h>

using namespace std;

int dp[100];

int lis(int n, int *arr)
{
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int len = dp[0];
    for (int i = 1; i < n; i++)
    {
        len = max(len, dp[i]);
    }
    return len;
}

int main()
{
    int n = 6;
    int arr[6] = {10, 5, 18, 7, 2, 9};
    printf("%d\n", lis(n, arr));
}