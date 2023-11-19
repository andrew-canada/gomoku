#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[4] = {1, 2, 3, 4};
    auto it = lower_bound(arr, arr + 4, 3);
    printf("%d\n", it);
    printf("%d\n", it - arr);

    int arr1[4] = {4, 3, 2, 1};
    it = lower_bound(arr1, arr1 + 4, 3);
    printf("%d\n", it);
    printf("%d\n", it - arr1);

    int arr2[4] = {-4, -3, -2, -1};
    it = lower_bound(arr2, arr2 + 4, -3);
    printf("%d\n", it);
    printf("%d\n", it - arr2);
}