#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int M = 1e9 + 7, mxX = 1e6;

int freq[mxX + 1];

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        memset(freq, 0, sizeof(freq));
        int x;
        cin >> x;
        for (int i = 1; i <= x; i++)
        {
            for (int j = i; j <= x; j += i)
            {
                freq[j]++;
            }
        }
        cout << freq[x] << '\n';
    }
}