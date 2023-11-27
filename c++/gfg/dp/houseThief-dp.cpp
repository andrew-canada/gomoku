#include <bits/stdc++.h>

using namespace std;

int maxVal(int *arr, int n, int i, bool canTake);

int dp[100][2];

int main()
{
    int n = 5;
    int arr[5] = {5, 3, 4, 11, 2};
    printf("%d\n", maxVal(arr, n, 0, true));
}

int maxVal(int *arr, int n, int i, bool canTake)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][canTake])
    {
        return dp[i][canTake];
    }
    int take = 0, noTake = 0;
    if (canTake)
    {
        take = arr[i] + maxVal(arr, n, i + 1, false);
    }
    noTake = maxVal(arr, n, i + 1, true);
    return dp[i][canTake] = max(take, noTake);
}