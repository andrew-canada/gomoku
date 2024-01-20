#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int n, k;
array<int, 3> arr[mxN + 1];
int setNum[mxN + 1];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][1] >> arr[i][0];
        arr[i][2] = i;
    }
    sort(arr, arr + n);
    int ans = 0;
    set<array<int, 2>> s;
    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound({arr[i][1] + 1});
        if (it != s.begin())
        {
            --it;
            s.erase(it);
            setNum[arr[i][2]] = (*it)[1];
        }
        else
        {
            setNum[arr[i][2]] = s.size();
        }
        if (s.size() < k)
        {
            ans++;
            s.insert({arr[i][0], setNum[arr[i][2]]});
        }
    }
    cout << ans;
}