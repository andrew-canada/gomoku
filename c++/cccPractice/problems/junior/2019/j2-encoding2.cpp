#include <stdio.h>

int l, n;
char c;

int main()
{
    scanf("%d", &l);
    for (int i = 0; i < l; i++)
    {
        scanf("%d %c", &n, &c);
        for (int i = 0; i < n; i++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
}