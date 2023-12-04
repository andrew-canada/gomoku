#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int mc(int *arr, int l, int r);

int main()
{
    int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    printf("%d\n", mc(arr, 0, 19));
}

int mc(int *arr, int l, int r)
{
    if (l + 1 == r)
    {
        return 0;
    }
    int prod = INF;
    for (int i = l + 1; i < r; i++)
    {
        prod = min(prod, mc(arr, l, i) + mc(arr, i, r) + arr[l] * arr[i] * arr[r]);
    }
    return prod;
}