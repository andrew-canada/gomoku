#include <bits/stdc++.h>

using namespace std;

int ns(int n, int sum);

int arr[3] = {2, 5, 3};

int main()
{
    int n = 3;
    int sum = 5;
    printf("%d\n", ns(n, sum));
}

int ns(int n, int sum)
{
    if (n == 0 || sum <= 0)
    {
        return sum == 0;
    }
    return ns(n - 1, sum) + ns(n - 1, sum - arr[n - 1]);
}