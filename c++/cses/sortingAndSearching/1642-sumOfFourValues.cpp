#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e3;

int arr[mxN + 1];
// don't use unordered_map unless if very small dataset
map<int, array<int, 2>> mp;

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mp.find(x - arr[i] - arr[j]) != mp.end())
            {
                array<int, 2> rem = mp[x - arr[i] - arr[j]];
                cout << i + 1 << " " << j + 1 << " " << rem[0] + 1 << " " << rem[1] + 1;
                return 0;
            }
        }
        for (int j = 0; j < i; j++)
        {
            mp[arr[i] + arr[j]] = {i, j};
        }
    }
    cout << "IMPOSSIBLE\n";
}