#include <stdio.h>
#include <string>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

int n;
char str[35];
string names1[35];
string names2[35];

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%s", &str);
        names1[i] = str;
    }
    REP(i, 0, n)
    {
        scanf("%s", &str);
        names2[i] = str;
    }

    REP(i, 0, n)
    {
        string cur = names1[i];
        string p = names2[i];
        if (cur == p)
        {
            printf("bad");
            return 0;
        }
        REP(j, 0, n)
        {
            if (names1[j] == p && names2[j] != cur)
            {
                printf("bad");
                return 0;
            }
        }
    }
    printf("good");
}