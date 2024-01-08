#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

int arr[mxN + 1];
map<int, int> freq;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < n && freq[arr[j]] < 1)
        {
            freq[arr[j]]++;
            j++;
        }
        ans = max(ans, j - i);
        freq[arr[i]]--;
    }
    cout << ans;
}