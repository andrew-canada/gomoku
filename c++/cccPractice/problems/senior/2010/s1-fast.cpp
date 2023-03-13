#include <stdio.h>
#include <cstring>

char n1[20] = "", n2[20] = "", nCur[20];
int v1, v2, vCur;
int r, s, d;
int n;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s %d %d %d", &nCur, &r, &s, &d);
        vCur = 2 * r + 3 * s + d;
        if (vCur > v1 || vCur == v1 && strcmp(nCur, n1) < 0)
        {
            strcpy(n2, n1);
            v2 = v1;
            strcpy(n1, nCur);
            v1 = vCur;
        }
        else if (vCur > v2 || vCur == v2 && strcmp(nCur, n2) < 0)
        {
            strcpy(n2, nCur);
            v2 = vCur;
        }
    }
    if (n1[0])
    {
        puts(n1);
    }
    if (n2[0])
    {
        puts(n2);
    }
}