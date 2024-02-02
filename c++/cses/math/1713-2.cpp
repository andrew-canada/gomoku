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
    for (int i = 1; i <= mxX; i++)
    {
        for (int j = i; j <= mxX; j += i)
        {
            freq[j]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cout << freq[x] << '\n';
    }
}