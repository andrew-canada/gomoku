#include <bits/stdc++.h>

using namespace std;

double et(int n, int three, int two, int one);

int dp[100][100][100];

int main()
{
    memset(dp, -1, sizeof(dp));
    int n = 3;
    // int arr[3] = {1, 1, 1};
    printf("%lf\n", et(n, 0, 0, 3));
}

double et(int n, int three, int two, int one)
{
    if (three == 0 && two == 0 && one == 0)
    {
        return 0;
    }
    if (dp[three][two][one] != -1)
    {
        return dp[three][two][one];
    }
    double e = 0;
    e = (double)(n - three - two - one) / n;
    if (three > 0)
    {
        e += (double)three / n * (1 + et(n, three - 1, two + 1, one));
    }
    if (two > 0)
    {
        e += (double)two / n * (1 + et(n, three, two - 1, one + 1));
    }
    if (one > 0)
    {
        e += (double)one / n * (1 + et(n, three, two, one - 1));
    }
    e /= 1 - (double)(n - three - two - one) / n;
    dp[three][two][one] = e;
    return e;
}