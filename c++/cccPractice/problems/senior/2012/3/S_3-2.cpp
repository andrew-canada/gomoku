#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int mxN = 2e6, mxR = 1e3;

int arr[mxN + 1];
// frequency, number
vector<array<int, 2>> freq;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int prev = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == prev)
        {
            freq.back()[0]++;
        }
        else
        {
            freq.pb({1, arr[i]});
            prev = arr[i];
        }
    }
    sort(freq.begin(), freq.end(), greater<array<int, 2>>());
    int v1, v2, v3, v4;
    v1 = freq[0][1];
    int idx;
    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i][0] != freq[0][0])
        {
            v2 = freq[i - 1][1];
            v3 = freq[i][1];
            idx = i;
            break;
        }
        if (i == freq.size() - 1)
        {
            v2 = freq[i][1];
        }
    }
    if (v1 ^ v2)
    {
        cout << v1 - v2;
        return 0;
    }
    for (int i = idx; i < freq.size(); i++)
    {
        if (freq[i][0] != freq[idx][0] || i == freq.size() - 1)
        {
            v4 = freq[i - 1][1];
            break;
        }
    }
    cout << max(abs(v1 - v4), abs(v2 - v3));
}