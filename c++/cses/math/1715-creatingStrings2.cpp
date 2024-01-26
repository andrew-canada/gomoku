#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef unsigned long long ull;

const int M = 1e9 + 7, mxA = 1e6;

int freq[200];
ull f1[mxA + 1], f2[mxA + 1], inv[mxA + 1];

int main()
{
    string s;
    cin >> s;
    for (char c : s)
    {
        freq[c]++;
    }
    int n = s.size();
    inv[1] = 1;
    for (int i = 2; i <= mxA; i++)
    {
        inv[i] = M - M / i * inv[M % i] % M;
    }
    f1[0] = f2[0] = 1;
    for (int i = 1; i <= mxA; i++)
    {
        f1[i] = f1[i - 1] * i % M;
        f2[i] = f2[i - 1] * inv[i] % M;
    }
    ull ans = f1[n];
    for (int i = 'a'; i <= 'z'; i++)
    {
        ans = ans * f2[freq[i]] % M;
    }
    cout << ans;
}