#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e4;

char c[mxN];

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    char x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == c[i])
        {
            ans++;
        }
    }
    cout << ans;
}