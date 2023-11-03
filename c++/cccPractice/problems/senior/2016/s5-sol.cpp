#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool *oldBits = new bool[100000];
bool *newBits = new bool[100000];

int main()
{
    cin.sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    ll t;
    cin >> n;
    cin >> t;

    string str;
    cin >> str;
    for (int i = 0; i < n; i++)
        oldBits[i] = str[i] == '1';

    ll pwr2 = 1LL << 60;
    for (int i = 60; i > 0; i--)
    {
        pwr2 >>= 1;
        if (pwr2 > t)
            continue;
        t -= pwr2;

        int a = pwr2 % n;
        int b = n - a;

        for (int j = 0; j < n; j++)
        {
            newBits[j] = oldBits[a] ^ oldBits[b];
            if (++a == n)
                a = 0;
            if (++b == n)
                b = 0;
        }

        bool *temp = oldBits;
        oldBits = newBits;
        newBits = temp;
    }

    for (int i = 0; i < n; i++)
        cout << oldBits[i];
    cout << '\n';
}