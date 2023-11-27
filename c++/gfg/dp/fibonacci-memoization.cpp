#include <bits/stdc++.h>

using namespace std;

int dp[100];

int fib(int n)
{
    dp[0] = 0, dp[1] = 1;
    if (dp[n])
    {
        return dp[n];
    }
    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
    printf("%d\n", fib(5));
}