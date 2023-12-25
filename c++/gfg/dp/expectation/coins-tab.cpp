#include <bits/stdc++.h>

using namespace std;

double prob(int n, double *arr, int c, int h);

double dp[100][100];

int main()
{
    fill(&dp[0][0], &dp[0][0] + 10000, -1.0);
    int n = 3;
    double arr[3] = {0.3, 0.6, 0.8};
    printf("%lf\n", prob(n, arr, 0, 0));
}

double prob(int n, double *arr, int c, int h)
{
    if (c == n)
    {
        if (h > n - h)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[c][h] != -1)
    {
        return dp[c][h];
    }
    double p = 0;
    p += arr[c] * prob(n, arr, c + 1, h + 1);
    p += (1 - arr[c]) * prob(n, arr, c + 1, h);
    dp[c][h] = p;
    return p;
}