#include <stdio.h>
#include <cstring>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int H1 = 1e9 + 7, H2 = 1e9 + 17;
int freqN[26], freqH[26];
char n[200005], h[200005];
unordered_set<ll> hashedPerms;
int numPerms;

ll getHash(ll hash1, ll hash2)
{
    return hash1 * 7 + hash2 * 11;
}

int main()
{
    fgets(n, 200005, stdin);
    fgets(h, 200005, stdin);
    int ln = strlen(n), lh = strlen(h);
    string sn(n), sh(h);
    for (char c : n)
    {
        freqN[c - 'a']++;
    }

    ll curHash1 = 0, curHash2 = 0;
    ll hashVal1 = 1, hashVal2 = 1;
    for (int i = 0; i < ln; i++)
    {
        hashVal1 = hashVal1 * 26 % H1;
        hashVal2 = hashVal2 * 26 % H2;
    }

    for (int i = 0; i < lh; i++)
    {
        freqH[sh[i] - 'a']++;
        curHash1 = (curHash1 * 26 + sh[i] - 'a') % H1;
        curHash2 = (curHash2 * 26 + sh[i] - 'a') % H2;
        bool isPerm = true;
        if (i >= ln - 1)
        {
            for (int i = 0; i < 26; i++)
            {
                if (freqN[i] != freqH[i])
                {
                    isPerm = false;
                    break;
                }
            }
        }
        if (isPerm && hashedPerms.find(getHash(curHash1, curHash2)) == hashedPerms.end())
        {
            hashedPerms.insert(getHash(curHash1, curHash2));
            numPerms++;
        }
        curHash1 = (curHash1 - (sh[i - ln + 1] - 'a') * hashVal1 + H1) % H1;
        curHash2 = (curHash2 - (sh[i - ln + 1] - 'a' * hashVal2 + H2) % H2);
        freqH[sh[i - ln + 1] - 'a']--;
    }
    printf("%d", numPerms);
}