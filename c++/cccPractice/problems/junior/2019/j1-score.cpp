#include <stdio.h>

int main()
{
    int a3, a2, a1;
    scanf("%d%d%d", &a3, &a2, &a1);

    int b3, b2, b1;
    scanf("%d%d%d", &b3, &b2, &b1);

    int apple = 3 * a3 + 2 * a2 + a1;
    int banana = 3 * b3 + 2 * b2 + b1;

    if (apple > banana)
    {
        puts("A");
    }
    else if (apple < banana)
    {
        puts("B");
    }
    else
    {
        puts("T");
    }
}