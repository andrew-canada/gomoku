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
    int ans = 0, lastEnd = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][1] >= lastEnd)
        {
            ans++;
            lastEnd = arr[i][0];
        }
    }
    cout << ans;
}