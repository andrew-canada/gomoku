#include <bits/stdc++.h>

using namespace std;

set<array<int, 2>> s;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        s.insert({a, 1}), s.insert({b, -1});
    }
    int cur = 0, ans = 0;
    for (array<int, 2> arr : s)
    {
        cur += arr[1];
        ans = max(ans, cur);
    }
    cout << ans;
}