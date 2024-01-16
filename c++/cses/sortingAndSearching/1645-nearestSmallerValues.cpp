#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 2e5;

int arr[mxN + 1];
int idx[mxN + 1];

int main()
{
    int n;
    cin >> n;
    int x;
    arr[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    idx[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            cout << i - 1 << " ";
            idx[i] = i - 1;
        }
        else
        {
            int cur = i - 1;
            while (arr[idx[cur]] >= arr[i])
            {
                cur = idx[cur];
            }
            if (arr[idx[cur]] == -1)
            {
                cout << "0 ";
                idx[i] = 0;
            }
            else
            {
                cout << idx[cur] << " ";
                idx[i] = idx[cur];
            }
        }
    }
}