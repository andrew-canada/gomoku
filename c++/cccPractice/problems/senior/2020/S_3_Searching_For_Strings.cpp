#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

char Nstr[200005], Hstr[200005];
int fN[26], fH[26];
unordered_set<ll> s;
ll mod1 = 1e9 + 3, mod2 = 1e9 + 13;

ll hashStr(ll hs1, ll hs2);

int main()
{
    scanf("%s%s", Nstr, Hstr);
    string n(Nstr);
    string h(Hstr);
    for (char c : n)
    {
        fN[c - 'a']++;
    }
    ll hash1 = 1, hash2 = 1;
    REP(i, 0, n.length() - 1)
    {
        hash1 = hash1 * 26 % mod1;
        hash2 = hash2 * 26 % mod2;
    }
    bool perm;
    int np = 0;
    ll hStr1 = 0, hStr2 = 0;
    REP(i, 0, h.length())
    {
        fH[h[i] - 'a']++;
        hStr1 = (hStr1 * 26 + h[i] - 'a') % mod1;
        hStr2 = (hStr2 * 26 + h[i] - 'a') % mod2;
        if (i < n.length() - 1)
        {
            continue;
        }
        perm = true;
        REP(i, 0, 26)
        {
            if (fN[i] != fH[i])
            {
                perm = false;
                break;
            }
        }
        if (perm)
        {
            np++;
            s.insert(hashStr(hStr1, hStr2));
        }
        fH[h[i - n.length() + 1] - 'a']--;
        hStr1 = ((hStr1 - (h[i - n.length() + 1] - 'a') * hash1) % mod1 + mod1) % mod1;
        hStr2 = ((hStr2 - (h[i - n.length() + 1] - 'a') * hash2) % mod2 + mod2) % mod2;
    }
    printf("%d", s.size());
}

ll hashStr(ll hs1, ll hs2)
{
    return 7 * hs1 + 17 * hs2;
}