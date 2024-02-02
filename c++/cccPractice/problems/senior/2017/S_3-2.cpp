#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e6;

int arr[4001];

int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[x]++;
    }
    int mxL = 0, nf = 0;
    for (int i = 2; i <= 4000; i++)
    {
        int curL = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            if (arr[j] && arr[i - j])
            {
                if (j == i - j)
                {
                    curL += arr[j] / 2;
                }
                else
                {
                    curL += min(arr[j], arr[i - j]);
                }
            }
        }
        if (curL > mxL)
        {
            mxL = curL, nf = 1;
        }
        else if (curL == mxL)
        {
            nf++;
        }
    }
    cout << mxL << " " << nf;
}