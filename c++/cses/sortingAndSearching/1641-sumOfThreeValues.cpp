#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 5e3;

array<int, 2> arr[mxN + 1];

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i][0], arr[i][1] = i;
    }
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int rem = x - arr[i][0];
        for (int j = i + 1, k = n; j < k; j++)
        {
            while (j < k && arr[j][0] + arr[k][0] > rem)
            {
                k--;
            }
            if (j < k && arr[j][0] + arr[k][0] == rem)
            {
                cout << arr[i][1] << " " << arr[j][1] << " " << arr[k][1];
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}