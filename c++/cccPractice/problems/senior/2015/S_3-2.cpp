#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxA = 1e6, mxG = 1e5;

bool arr[mxG + 1];

int main()
{
    memset(arr, true, sizeof(arr));
    int g, p, x, ans = 0;
    cin >> g >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> x;
        int j = x;
        for (; j >= 1; j--)
        {
            if (arr[j])
            {
                arr[j] = false;
                ans++;
                break;
            }
        }
        if (j == 0)
        {
            break;
        }
    }
    cout << ans;
}

/*
4
6
2
2
3
3
4
4
*/