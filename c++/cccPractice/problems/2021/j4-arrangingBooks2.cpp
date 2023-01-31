#include <stdio.h>
#include <string>

#define min(a, b) (a < b ? a : b)

int l, m;
int wl, wm;
int mInL, lInM;
char in[500001];

int main()
{
    scanf("%s", &in);
    std::string s(in);
    for (char c : s)
    {
        if (c == 'L')
        {
            l += 1;
        }
        else if (c == 'M')
        {
            m += 1;
        }
    }
    for (int i = 0; i < l; i++)
    {
        if (s[i] != 'L')
        {
            wl += 1;
        }
        if (s[i] == 'M')
        {
            mInL += 1;
        }
    }

    for (int i = l; i < l + m; i++)
    {
        if (s[i] != 'M')
        {
            wm += 1;
        }
        if (s[i] == 'L')
        {
            lInM += 1;
        }
    }
    printf("%d", wl + wm - min(mInL, lInM));
}