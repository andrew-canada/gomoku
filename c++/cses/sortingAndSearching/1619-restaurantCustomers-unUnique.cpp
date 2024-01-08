#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

set<array<int, 2>> s;

int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        s.insert({a, 1}), s.insert({b, -1});
        // s.insert({2 * a, 1}), s.insert({2 * b + 1, -1});
    }
    int ans = 0, cur = 0;
    for (array<int, 2> a : s)
    {
        cur += a[1];
        ans = max(ans, cur);
    }
    cout << ans;
}