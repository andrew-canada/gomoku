#include <bits/stdc++.h>

using namespace std;

int ns(int n, int sum);

int arr[3] = {2, 5, 3};
int dp[100][100];

int main()
{
    int n = 3;
    int sum = 5;
    printf("%d\n", ns(n, sum));
}

int ns(int n, int sum)
{
    for (int j = 1; j <= sum; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][sum];
}