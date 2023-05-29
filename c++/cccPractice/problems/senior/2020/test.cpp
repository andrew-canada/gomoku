#include <stdio.h>
#include <cstring>
#include <algorithm>

char n[200005];
char h[200005];
int num;

int main()
{
    // fgets(n, 200005, stdin);
    // fgets(h, 200005, stdin);
    // int len = strlen(n);
    if (strstr("abacabaa", "aab") != NULL)
    {
        printf("%d\n", 1);
    }
    if (strstr("abacabaa", "aba") != NULL)
    {
        printf("%d\n", 2);
    }
    if (strstr("abacabaa", "baa") != NULL)
    {
        printf("%d", 3);
    }
}