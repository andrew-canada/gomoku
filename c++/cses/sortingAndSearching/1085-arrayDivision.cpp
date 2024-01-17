#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int arr[mxN + 1];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll l = *max_element(arr, arr + n), r = 2e14;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        ll curS = 0;
        int ns = 0;
        for (int i = 0; i < n; i++)
        {
            if (curS + arr[i] > mid)
            {
                ns++;
                curS = 0;
            }
            curS += arr[i];
        }
        ns++;
        if (ns > k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << r;
}