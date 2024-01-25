#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int M = 1e9 + 7, mxN = 2e5, mxX = 1e6;

int freq[mxX + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    for (int i = mxX; i >= 1; i--)
    {
        int num = 0;
        for (int j = i; j <= mxX; j += i)
        {
            num += freq[j];
        }
        if (num >= 2)
        {
            cout << i;
            break;
        }
    }
}