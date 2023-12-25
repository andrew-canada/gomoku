// n lines
// each line has at most 100 characters, with space
// count number of t/T and s/S

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, t, s;
string text;

int main()
{
    scanf("%d", &n);
    getline(cin, text);
    while (n--)
    {
        getline(cin, text);
        for (char c : text)
        {
            if (c == 't' || c == 'T')
            {
                t++;
            }
            else if (c == 's' || c == 'S')
            {
                s++;
            }
        }
    }
    t > s ? printf("English") : printf("French");
}