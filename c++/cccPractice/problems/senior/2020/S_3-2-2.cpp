#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 4e9 + 7, numC = 26;

int fN[27], fH[27];

int main()
{
    string n, h;
    cin >> n >> h;
    int nl = n.size(), hl = h.size();
    set<ll> s;
    ll mxH = 1;
    for (int i = 0; i < nl; i++)
    {
        mxH = (mxH * numC) % M;
    }
    ll hh = 0;
    for (int i = 0; i < nl; i++)
    {
        fN[n[i] - 'a' + 1]++, fH[h[i] - 'a' + 1]++;
        hh = (hh * numC + (h[i] - 'a' + 1)) % M;
    }
    for (int i = 0; i <= hl - nl; i++)
    {
        bool found = true;
        for (int j = 1; j <= 26; j++)
        {
            if (fN[j] != fH[j])
            {
                found = false;
            }
        }
        if (found)
        {
            s.insert(hh);
        }
        if (i < hl - nl)
        {
            fH[h[i] - 'a' + 1]--;
            fH[h[i + nl] - 'a' + 1]++;
            hh = (hh * numC + (h[i] - 'a' + 1) * (M - mxH) + (h[i + nl] - 'a' + 1)) % M;
        }
    }
    cout << s.size();
}