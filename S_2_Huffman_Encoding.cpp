// given bit sequence of k characters
// given bit sentence (at most 250 bits), translate to characters

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

char c[25];
char s[25];
string seq[25];
char bits[255];

int main()
{
    int k;
    scanf("%d", &k);
    REP(i, 0, k)
    {
        scanf(" %c%s", &c[i], &s);
        seq[i] = s;
    }
    scanf("%s", &bits);
    string bt = bits;
    int start = 0;
    while (start < bt.length())
    {
        REP(i, 0, k)
        {
            if (seq[i] == bt.substr(start, seq[i].length()))
            {
                printf("%c", c[i]);
                start += seq[i].length();
                i--;
            }
        }
    }
}