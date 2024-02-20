#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const ll numChar = 26, M = 3e9 + 7;

int fs[numChar + 1], ft[numChar + 1];

int rabinKarp(string s, string t)
{
    set<int> st;
    int sl = s.size(), tl = t.size();
    ll mxH = 1;
    for (int i = 0; i < tl - 1; i++)
    {
        mxH = (mxH * numChar) % M;
    }
    ll sh = 0;
    for (int i = 0; i < tl; i++)
    {
        fs[s[i] - 'a' + 1]++, ft[t[i] - 'a' + 1]++;
        sh = (sh * numChar + (s[i] - 'a' + 1)) % M;
    }
    for (int i = 0; i <= sl - tl; i++)
    {
        bool valid = true;
        for (int i = 1; i <= 26; i++)
        {
            if (fs[i] != ft[i])
            {
                valid = false;
            }
        }
        if (valid)
        {
            st.insert(sh);
        }
        if (i < sl - tl)
        {
            fs[s[i] - 'a' + 1]--, fs[s[i + tl] - 'a' + 1]++;
            sh = ((sh - (s[i] - 'a' + 1) * mxH + M) * numChar + (s[i + tl] - 'a' + 1)) % M;
            if (sh < 0)
            {
                sh += M;
            }
            // cout << sh << '\n';
        }
    }
    return st.size();
}

int main()
{
    // freopen("S_3.in", "r", stdin);
    // freopen("S_3.out", "w", stdout);
    string s, t;
    cin >> t >> s;
    cout << rabinKarp(s, t);
}