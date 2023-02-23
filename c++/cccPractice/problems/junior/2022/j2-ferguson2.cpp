#include <stdio.h>

int main()
{
    int n, p, f, c;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &p, &f);
        if ((p * 5 - f * 3) > 40)
        {
            c += 1;
        }
    }
    printf("%d", c);
    if (c == n)
    {
        printf("+");
    }
}