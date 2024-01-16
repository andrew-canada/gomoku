#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 2e5;

int arr[mxN + 1], nl[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        nl[i] = i - 1;
        while (~nl[i] && arr[nl[i]] >= arr[i])
        {
            nl[i] = nl[nl[i]];
        }
        cout << nl[i] + 1 << " ";
    }
}