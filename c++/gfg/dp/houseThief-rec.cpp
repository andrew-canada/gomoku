#include <bits/stdc++.h>

using namespace std;

int maxVal(int *arr, int n, int i, bool canTake);

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
    int take = 0, noTake = 0;
    if (canTake)
    {
        take = arr[i] + maxVal(arr, n, i + 1, false);
    }
    noTake = maxVal(arr, n, i + 1, true);
    return max(take, noTake);
}