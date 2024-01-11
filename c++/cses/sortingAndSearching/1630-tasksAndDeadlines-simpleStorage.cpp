#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

// order of deadline doesn't matter
array<int, 2> arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr, arr + n);
    ll ans = 0, ct = 0;
    for (int i = 0; i < n; i++)
    {
        ct += arr[i][0];
        ans += arr[i][1] - ct;
    }
    cout << ans;
}