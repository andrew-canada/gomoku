#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

ll med, ans;
int arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    med = arr[n / 2];
    for (int i = 0; i < n; i++)
    {
        ans += abs(arr[i] - med);
    }
    cout << ans;
}