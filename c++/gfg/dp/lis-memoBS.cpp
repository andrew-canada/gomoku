#include <bits/stdc++.h>

using namespace std;

int dp[100];

int lis(int n, int *arr)
{
    dp[0] = 1;
    int low, high, mid;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        low = 0, high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] < arr[i])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        dp[i] = max(dp[i], dp[mid] + 1);
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