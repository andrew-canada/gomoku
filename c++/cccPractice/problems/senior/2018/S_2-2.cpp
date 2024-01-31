#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxN = 100;

int arr[mxN + 1][mxN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int tl = arr[0][0], tr = arr[0][n - 1], bl = arr[n - 1][0], br = arr[n - 1][n - 1];
    if (tl <= tr && tl <= bl && tr <= br)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
    }
    else if (tr <= tl && tr <= bl && tr <= br)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
    }
    else if (bl <= tl && bl <= tr && bl <= br)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
    }
}