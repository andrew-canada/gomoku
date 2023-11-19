#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

bool isPossible(int n, int *arr)
{
    int xorVal = arr[0];
    REP(i, 1, n)
    {
        xorVal ^= arr[i];
    }
    if (!xorVal)
    {
        return true;
    }
    int cur = arr[0], num = 0;
    REP(i, 1, n)
    {
        cur ^= arr[i];
        if (cur == xorVal)
        {
            cur = 0;
            num++;
        }
    }
    return num == 3;
}

int main()
{
    int n = 3;
    int arr1[3] = {2, 0, 2};
    isPossible(n, arr1) ? printf("Yes\n") : printf("No\n");

    n = 4;
    int arr2[4] = {2, 3, 1, 10};
    isPossible(n, arr1) ? printf("Yes\n") : printf("No\n");
}