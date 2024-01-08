#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 2e5;

array<int, 2> arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][1] >> arr[i][0];
    }
    sort(arr, arr + n);
    set<array<int, 2>> dp;
    dp.insert({0, 0});
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = dp.upper_bound({arr[i][1], INF});
        --it;
        ans = max(ans, (*it)[1] + 1);
        dp.insert({arr[i][0], ans});
    }
    cout << ans;
}