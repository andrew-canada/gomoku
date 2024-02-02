#include <bits/stdc++.h>

using namespace std;

const int mxN = 100;

int arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    if (n % 2)
    {
        cout << arr[n / 2] << " ";
        int d = 2;
        for (int i = n / 2 + 1; i < n; i++)
        {
            cout << arr[i] << " " << arr[i - d] << " ";
            d += 2;
        }
    }
    else
    {
        int d = 1;
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            cout << arr[i] << " " << arr[i + d] << " ";
            d += 2;
        }
    }
}