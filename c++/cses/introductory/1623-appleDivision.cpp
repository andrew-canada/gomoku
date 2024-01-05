#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int arr[21];

int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    ll ans = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        ll curSum = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                curSum += arr[j];
            }
        }
        if (curSum <= sum / 2)
        {
            ans = max(ans, curSum);
        }
    }
    cout << sum - 2 * ans;
}