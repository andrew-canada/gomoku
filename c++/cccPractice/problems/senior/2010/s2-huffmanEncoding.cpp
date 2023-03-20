#include <stdio.h>
#include <string>

using namespace std;

// #define LOCAL
#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

int n;
char seq[255];
char c[25];
string s[25];
string line;

int main()
{
#ifdef LOCAL
    freopen("s2.in", "r", stdin);
    freopen("s2.out", "w", stdout);
#endif
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf(" %c %s", &c[i], &seq);
        s[i] = seq;
    }
    scanf(" %s", &seq);
    line = seq;
    while (true)
    {
        bool end = true;
        REP(i, 0, n)
        {
            int pos = line.find(s[i]);
            if (pos == 0)
            {
                end = false;
                printf("%c", c[i]);
                line = line.substr(s[i].length());
                i -= 1;
            }
        }
        if (end)
        {
            return 0;
        }
    }
}