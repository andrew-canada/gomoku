#include <stdio.h>

int n;
int x, y;
int bx = 101, by = 101;
int tx, ty;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d, %d", &x, &y);
        if (x < bx)
        {
            bx = x;
        }
        if (y < by)
        {
            by = y;
        }
        if (x > tx)
        {
            tx = x;
        }
        if (y > ty)
        {
            ty = y;
        }
    }
    printf("%d,%d\n", bx - 1, by - 1);
    printf("%d,%d", tx + 1, ty + 1);
}