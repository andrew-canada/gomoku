#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

char w1[105], w2[105];
int f1[125], f2[125];

int main()
{
    scanf("%s%s", &w1, &w2);
    f1['*'] = 105;
    for (char c : w1)
    {
        f1[c]++;
    }
    for (char c : w2)
    {
        f2[c]++;
        if (f2[c] > f1[c])
        {
            printf("N");
            return 0;
        }
    }
    printf("A");
}