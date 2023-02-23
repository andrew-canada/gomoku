#include <stdio.h>

int main()
{
    int month, day, val;
    scanf("%d%d", &month, &day);
    val = month * 100 + day;

    if (val == 218)
    {
        puts("Special");
    }
    else if (val < 218)
    {
        puts("Before");
    }
    else
    {
        puts("After");
    }
}