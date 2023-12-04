#include <bits/stdc++.h>

using namespace std;

const int INF = -0x3f3f3f3f;
int dp[100];

int kadane(int *arr, int n)
{
    int ms = arr[0];
    for (int i = 1; i < n; i++)
    {
        ms = max(ms + arr[i], arr[i]);
    }
    return ms;
}

int main()
{
    int n = 7;
    int arr[7] = {2, 3, -7, 5, -1, 4, -3};
    printf("%d\n", kadane(arr, n));
}