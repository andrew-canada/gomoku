#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1e5, mxX = 1e6, M = 1e9 + 7;

int freq[mxX + 1];

int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }
    // divisor
    for (int i = mxX; i >= 1; i--)
    {
        int ans = 0;
        // multiples of divisor
        for (int j = i; j <= mxX; j += i)
        {
            ans += freq[j];
        }
        if (ans >= 2)
        {
            cout << i;
            break;
        }
    }
}