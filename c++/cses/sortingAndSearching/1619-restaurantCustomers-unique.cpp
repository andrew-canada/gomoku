#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

int s[mxN + 1], e[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> e[i];
    }
    sort(s, s + n), sort(e, e + n);
    int i = 0, j = 0, ans = 0, cur = 0;
    while (i < n && j < n)
    {
        if (s[i] < e[j])
        {
            i++, cur++;
        }
        else
        {
            j++, cur--;
        }
        ans = max(ans, cur);
    }
    cout << ans;
}