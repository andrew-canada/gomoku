#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

char t;
int n;
int s1[105], s2[105];
int ts;

int main()
{
    scanf("%c%d", &t, &n);
    REP(i, 0, n)
    {
        scanf("%d", &s1[i]);
    }
    REP(i, 0, n)
    {
        scanf("%d", &s2[i]);
    }
    if (t == '1')
    {
        sort(s1, s1 + n);
        sort(s2, s2 + n);
        REP(i, 0, n)
        {
            ts += max(s1[i], s2[i]);
        }
    }
    else
    {
        sort(s1, s1 + n);
        sort(s2, s2 + n, greater<int>());
        REP(i, 0, n)
        {
            ts += max(s1[i], s2[i]);
        }
    }
    printf("%d", ts);
}