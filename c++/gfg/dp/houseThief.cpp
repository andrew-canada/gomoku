#include <bits/stdc++.h>

using namespace std;

int ms(int *arr, int n);

int dp[100];

int main()
{
    int n = 5;
    int arr[5] = {5, 3, 4, 11, 2};
    printf("%d\n", ms(arr, n));
}

int ms(int *arr, int n)
{
    dp[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if ()
    }
}