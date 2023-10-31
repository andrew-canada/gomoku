#include <stdio.h>
#include <string>
#include <unordered_set>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int hashFactor1 = 1e9 + 7, hashFactor2 = 1e9 + 17;
char n[200005], h[200005];
int freqN[26], freqH[26];
unordered_set<ll> hashedPerm;
int numPerm;

ll getHash(ll h1, ll h2);

int main()
{
    scanf("%s%s", &n, &h);
    string sn(n), sh(h);
    int lenN = sn.length(), lenH = sh.length();
    for (char c : sn)
    {
        freqN[c - 'a']++;
    }
    bool isPerm;
    ll stringHashVal;
    ll hashVal1 = 1, hashVal2 = 1;
    ll stringHash1 = 0, stringHash2 = 0;
    REP(i, 0, lenN - 1)
    {
        hashVal1 = hashVal1 * 26 % hashFactor1;
        hashVal2 = hashVal2 * 26 % hashFactor2;
    }
    REP(i, 0, lenH)
    {
        freqH[sh[i] - 'a']++;
        isPerm = true;
        stringHash1 = (stringHash1 * 26 + sh[i] - 'a') % hashFactor1;
        stringHash2 = (stringHash2 * 26 + sh[i] - 'a') % hashFactor2;
        if (i < lenN - 1)
        {
            continue;
        }
        REP(i, 0, 26)
        {
            if (freqN[i] != freqH[i])
            {
                isPerm = false;
                break;
            }
        }
        stringHashVal = getHash(stringHash1, stringHash2);
        if (isPerm && hashedPerm.find(stringHashVal) == hashedPerm.end())
        {
            numPerm++;
            hashedPerm.insert(stringHashVal);
        }
        stringHash1 = ((stringHash1 - (sh[i - lenN + 1] - 'a') * hashVal1) % hashFactor1 + hashFactor1) % hashFactor1;
        stringHash2 = ((stringHash2 - (sh[i - lenN + 1] - 'a') * hashVal2) % hashFactor2 + hashFactor2) % hashFactor2;
        freqH[sh[i - lenN + 1] - 'a']--;
    }
    printf("%d", numPerm);
}

ll getHash(ll h1, ll h2)
{
    return h1 * 5 + h2 * 11;
}