#include <stdio.h>
#include <math.h>

int t, xx, yy;

bool isCrystal(int m, int x, int y);

int main()
{
    int m, x, y;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &m, &x, &y);
        isCrystal(m, x, y) ? printf("crystal\n") : printf("empty\n");
    }
}

bool isCrystal(int m, int x, int y)
{
    xx = x / pow(5, m - 1);
    yy = y / pow(5, m - 1);
    if (xx == 0 || xx == 4)
    {
        return false;
    }
    else if ((xx > 0 && xx < 4 && yy == 0) || (xx == 2 && yy == 1))
    {
        return true;
    }
    else if (((xx == 1 || xx == 3) && yy == 1) || (xx == 2 && yy == 2))
    {
        return isCrystal(m - 1, x % (int)pow(5, m - 1), y % (int)pow(5, m - 1));
    }
    return false;
}