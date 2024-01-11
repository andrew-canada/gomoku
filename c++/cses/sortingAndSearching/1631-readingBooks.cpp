#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i], s += arr[i];
    }
    sort(arr, arr + n);
    cout << max(s, 2ll * arr[n - 1]);
}