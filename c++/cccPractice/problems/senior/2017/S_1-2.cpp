#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;

int arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0, s1 = 0, s2 = 0, x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s1 += arr[i];
        s2 += x;
        if (s1 == s2)
        {
            ans = i + 1;
        }
    }
    cout << ans;
}